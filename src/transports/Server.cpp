//
// Created by 尹思维 on 2019-03-15.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <assert.h>
#include <list>
#include <arpa/inet.h>

#include <errno.h>


#define  MAX_CLIENT 10

#include "Server.h"

int Server::send(Message *msg) {
    return ::send(msg->session, msg->data.c_str(), msg->data.size(), 0);
}

int Server::poll(Message *msg) {
    static std::list<int> fds;
    struct sockaddr_in client_addr;
    socklen_t len;
    int fd = accept(this->sock_fd, (struct sockaddr *) &client_addr, &len);
    if (fd > 0) {
        fcntl(fd, F_SETFL, O_NONBLOCK);
        printf("[Server] Got connection from %s,port = %d, fd =  %d\n", inet_ntoa(client_addr.sin_addr),
               client_addr.sin_port, fd);
        fds.push_back(fd);
    }
    char buffer[1024];
    for (int fd:fds) {
        int n = recv(fd, buffer, sizeof(buffer), MSG_PEEK);
        if (n == 0 && errno == EWOULDBLOCK) {
            printf("[Server] Bye-bye fd = %d\n", fd);
            fds.remove(fd);
            return poll(msg);
        }
        if (n > 0) {
            assert(false && "receive");
            msg->session = fd;
            buffer[n] = '\0';
            msg->data = buffer;
            return 0;
        }
    }
}

void Server::start(int port) {
    struct sockaddr_in listen_addr;    /* my address information */
    int rc;
    this->sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    assert(sock_fd != -1 && "[Server]Socket Error.");


    listen_addr.sin_family = AF_INET;         /* host byte order */
    listen_addr.sin_port = htons(port);     /* short, network byte order */
    listen_addr.sin_addr.s_addr = INADDR_ANY; /* auto-fill with my IP */
    bzero(&(listen_addr.sin_zero), 8);        /* zero the rest of the struct */

//    rc = bind(this->sock_fd, (struct sockaddr *) &listen_addr, sizeof(struct sockaddr));
    assert(rc != -1 && "[Server]Bind Error.");

    rc = listen(this->sock_fd, MAX_CLIENT);
    assert(rc != -1 && "[Server]Listen Error");

    fcntl(this->sock_fd, F_SETFL, O_NONBLOCK);


    for (;;) {
        auto *msg = new Message;
        if (poll(msg)) {
            ServerSideRequestMessage serverSideRequestMessage  = {
                    .session = msg.session,
                    .msg = {
                            .
                    }
            };
            s2vvs(msg->data);
        }
    }


    return;
}

bool Server::registerEndpoint(AbstractRequestEndpoint &endpoint) {
    endpoints.push_back(endpoint);
    return true;
}