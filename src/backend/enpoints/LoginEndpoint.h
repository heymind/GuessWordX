//
// Created by 尹思维 on 2019-04-18.
//

#ifndef GUESSWORDX_LOGINENDPOINT_H
#define GUESSWORDX_LOGINENDPOINT_H


#include "../BasicEndpoint.h"

class LoginEndpoint : public BasicEndpoint {

public:
    bool handle(RequestMessage &req, vector<ResponseMessage> &responses) override;

};


#endif //GUESSWORDX_LOGINENDPOINT_H
