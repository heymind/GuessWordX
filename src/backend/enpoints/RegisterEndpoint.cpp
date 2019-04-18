//
// Created by 尹思维 on 2019-04-16.
//

#include "RegisterEndpoint.h"

#include <iostream>
#include <vector>

bool RegisterEndpoint::handle(RequestMessage &req, std::vector<ResponseMessage> &responses) {
    BEGIN_HANDLE("REGISTER_PLAYER")
            NOTIFY("INSERT INTO PLAYERS VALUES(NULL,?,?,0,0,0,0);" << PARAM(0) << PARAM(1));
        THEN_HANDLE("REGISTER_EXAMINER")
            NOTIFY("INSERT INTO EXAMINERS VALUES(NULL,?,?,0,0)" << PARAM(0) << PARAM(1));
    END_HANDLE;

}

