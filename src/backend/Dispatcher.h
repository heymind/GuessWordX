//
// Created by 尹思维 on 2019-04-16.
//

#ifndef BACKEND_DISPATCHER_H
#define BACKEND_DISPATCHER_H

#include "./AbstractRequestEndpoint.h"

class Dispatcher {
public:
    virtual bool registerEndpoint(AbstractRequestEndpoint *endpoint) = 0;

    virtual void send(ResponseMessage msg) = 0;
};

#endif //BACKEND_DISPATCHER_H
