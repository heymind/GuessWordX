//
// Created by 尹思维 on 2019-04-18.
//

#include "Backend.h"

void Backend::bindSessionPlayer(int session, int playerId) {
    onlinePlayers[session] = playerId;
}

void Backend::unbindSession(int session) {
    onlinePlayers.erase(session);
}


//void Backend::notifyOnlinePlayersToAllClient() {
//    vector<vector<string>> r;
//    ResponseMessage response;
//    db << "SELECT * FROM PLAYERS WHERE ONLINE = 1;" >> r;
//
//    for (auto iter = onlinePlayers.begin(); iter != onlinePlayers.end(); iter++) {
//        response = {
//                .session = iter->second,
//                .msg = {
//                        .eventName = "ONLINES",
//                        .rows = r,
//                        .errmsg  = ""
//                }
//        };
//        dispatcher->send(response);
//    }
//
//
//}

int Backend::getPlayerIdBySession(int session) {
    return onlinePlayers[session];
}


Backend::Backend(Dispatcher *dispatcher, const sqlite::database &db) : dispatcher(dispatcher), db(db) {}

void Backend::notifyAll(ClientSideResponseMessage msg) {
    ResponseMessage response;
    for (auto iter = onlinePlayers.begin(); iter != onlinePlayers.end(); iter++) {
        response = {
                .session = iter->second,
                .msg = msg
        };
        dispatcher->send(response);
    }
}

