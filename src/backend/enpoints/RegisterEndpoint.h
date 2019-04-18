//
// Created by 尹思维 on 2019-04-16.
//

#ifndef PROJECT_REGISTERENDPOINT_H
#define PROJECT_REGISTERENDPOINT_H

#include "../AbstractRequestEndpoint.h"

class RegisterEndpoint : public AbstractRequestEndpoint {
private:
    sqlite::database db;
public:
    bool handle(RequestMessage &req, vector<ResponseMessage> &responses) override;

    RegisterEndpoint(const sqlite::database &db);


};


#endif //PROJECT_REGISTERENDPOINT_H
