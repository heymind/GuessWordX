//
// Created by 尹思维 on 2019-04-16.
//

#ifndef TRANSPORT_COMMON_H
#define TRANSPORT_COMMON_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;
typedef struct client_side_response_message_t {
    string eventName;
    vector<vector<string>> rows;
    string errmsg;
} ClientSideResponseMessage;

typedef struct client_side_request_message_t {
    string actionName;
    vector<string> params;
} ClientSideRequestMessage;

typedef struct sever_side_response_message_t {
    int session;
    ClientSideResponseMessage msg;
} ServerSideResponseMessage;

typedef struct server_side_request_message_t {
    int session;
    ClientSideRequestMessage msg;
} ServerSideRequestMessage;

inline string clientSideRequestMessageToString(ClientSideRequestMessage &msg) {
    ostringstream ss;
    ss << msg.actionName << "$";
    for (auto param:msg.params) {
        ss << param << ',';
    }
    return ss.str();
}

inline ClientSideRequestMessage stringToClientSideRequestMessage(string &s) {
    ClientSideRequestMessage msg;
    vector<string> r;
    istringstream ss(s);
    getline(ss, msg.actionName, '$');
    while (ss.good()) {

        string param;
        getline(ss, param, ',');
        if(!param.empty()) r.push_back(param);
    }
    msg.params = r;
    return msg;
}

inline string clientSideResponseMessageToString(ClientSideResponseMessage &msg) {
    ostringstream ss;
    if (msg.errmsg.length() == 0) {
        ss << 0 << msg.eventName << "$";
        for (auto row:msg.rows) {
            for (auto item:row) {
                ss << item << ",";
            }
            ss << "|";
        }
    } else {
        ss << 1 << msg.eventName << "$";
        ss << msg.errmsg;

    }

    return ss.str();
}

inline ClientSideResponseMessage stringToClientSideResponseMessage(string &s) {
    ClientSideResponseMessage msg;
    vector<vector<string>> r;
    istringstream ss(s);
    int is_error;
    ss >> is_error;
    getline(ss, msg.eventName, '$');
    if (is_error) {
        ss >> msg.errmsg;
    } else {
        while (ss.good()) {
            vector<string> row;
            string line;
            getline(ss, line, '|');
            istringstream lss(line);
            while (lss.good()) {
                string item;
                getline(lss, item, ',');
                if(!item.empty()) row.push_back(item);
            }
            if(!row.empty()) r.push_back(row);
        }
        msg.rows = r;
    }
    return msg;
}

#endif //TRANSPORT_COMMON_H
