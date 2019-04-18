//
// Created by 尹思维 on 2019-04-18.
//

#ifndef GUESSWORDX_BASICENDPOINT_H
#define GUESSWORDX_BASICENDPOINT_H


#include "AbstractRequestEndpoint.h"
#include "Backend.h"

class BasicEndpoint : public AbstractRequestEndpoint {
protected:
    sqlite::database db;
    Backend *backend;
public:
    BasicEndpoint(const sqlite::database &db, Backend *backend);


};


#endif //GUESSWORDX_BASICENDPOINT_H
