//
// Created by 尹思维 on 2019-03-15.
//

#ifndef GUESSWORD_SERVER_H
#define GUESSWORD_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/unistd.h>
#include <string>
#include "../backend/Dispatcher.h"

typedef struct message_t {
    int session;
    std::string data;
} Message;

class Server : Dispatcher {
protected:
    int sock_fd;
public:
    int poll(Message *msg);

    int send(Message *msg);

    void start(int port);

private:
    vector<AbstractRequestEndpoint> endpoints;

    bool registerEndpoint(AbstractRequestEndpoint &endpoint) override;
};


#endif //GUESSWORD_SERVER_H
