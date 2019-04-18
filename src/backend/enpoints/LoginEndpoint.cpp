//
// Created by 尹思维 on 2019-04-18.
//

#include "LoginEndpoint.h"

bool LoginEndpoint::handle(RequestMessage &req, vector<ResponseMessage> &responses) {
    vector<vector<string>> rows;
    BEGIN_HANDLE("LOGIN_PLAYER")
            db << "SELECT * FROM PLAYERS WHERE USERNAME = ? and PASSWORD_HASHED = ?"
               << PARAM(0) << PARAM(1) >> rows;
            if (rows.size() > 0) {
                NOTIFY_DATA("LOGIN_PLAYER", rows);
                db << "UPDATE PLAYERS SET ONLINE = 1 WHERE ID = ? " << rows[0][0];
                backend->bindSessionPlayer(req.session, stoi(rows[0][0]));
            } else
                NOTIFY_ERR("LOGIN_ERROR", "用户名不存在或密码错误！");
        THEN_HANDLE("LOGIN_EXAMINER")
            db << "SELECT * FROM EXAMINER WHERE USERNAME = ? and PASSWORD_HASHED = ?"
               << PARAM(0) << PARAM(1) >> rows;
            if (rows.size() > 0) {
                NOTIFY_DATA("LOGIN_PLAYER", rows);
            } else
                NOTIFY_ERR("LOGIN_ERROR", "用户名不存在或密码错误！");
        THEN_HANDLE("LOGOUT")
            db << "UPDATE PLAYERS SET ONLINE = 0 WHERE ID = ? " << backend->getPlayerIdBySession(req.session);
    END_HANDLE;
}
