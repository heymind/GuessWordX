//
// Created by 尹思维 on 2019-04-16.
//

#ifndef PROJECT_REGISTERENDPOINT_H
#define PROJECT_REGISTERENDPOINT_H

#include "../BasicEndpoint.h"

class RegisterEndpoint : public BasicEndpoint {

public:
    bool handle(RequestMessage &req, vector<ResponseMessage> &responses) override;


};


#endif //PROJECT_REGISTERENDPOINT_H
