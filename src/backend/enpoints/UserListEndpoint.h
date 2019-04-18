//
// Created by 尹思维 on 2019-04-18.
//

#ifndef GUESSWORDX_USERLISTENDPOINT_H
#define GUESSWORDX_USERLISTENDPOINT_H


#include "../BasicEndpoint.h"

class UserListEndpoint : public BasicEndpoint {
public:
    bool handle(RequestMessage &req, vector<ResponseMessage> &responses) override;
};


#endif //GUESSWORDX_USERLISTENDPOINT_H
