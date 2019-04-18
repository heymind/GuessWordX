//
// Created by 尹思维 on 2019-04-18.
//

#include "UserListEndpoint.h"

bool UserListEndpoint::handle(RequestMessage &req, vector<ResponseMessage> &responses) {
    vector<vector<string>> r;
    BEGIN_HANDLE("ONLINES")
            db << "SELECT * FROM PLAYERS WHERE ONLINE = 1;" >> r;
            backend->notifyAll({
                                       .eventName = "ONLINES",
                                       .rows = r
                               });
        THEN_HANDLE("PLAYERS")
            db << "SELECT * FROM PLAYERS ORDER BY SCORE DESC;" >> r;
            backend->notifyAll({
                                       .eventName = "PLAYERS",
                                       .rows = r
                               });
        THEN_HANDLE("EXAMINERS")
            db << "SELECT * FROM EXAMINERS ORDER BY RANK DESC;" >> r;
            backend->notifyAll({
                                       .eventName = "EXAMINERS",
                                       .rows = r
                               });
    END_HANDLE;
}
