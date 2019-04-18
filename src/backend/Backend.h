//
// Created by 尹思维 on 2019-04-18.
//

#ifndef GUESSWORDX_BACKEND_H
#define GUESSWORDX_BACKEND_H


#include <map>

#include "common.h"
#include "Dispatcher.h"
#include "../models/PlayerModel.h"
class Backend {
private:
    map<int,int> onlinePlayers;
    Dispatcher *dispatcher;
    sqlite::database db;
public:
    Backend(Dispatcher *dispatcher, const sqlite::database &db);

public:
    void bindSessionPlayer(int session, int playerId);
    void unbindSession(int session);
    int getPlayerIdBySession(int session);
//    void notifyOnlinePlayersToAllClient();
    void notifyAll(ClientSideResponseMessage msg);
};


#endif //GUESSWORDX_BACKEND_H
