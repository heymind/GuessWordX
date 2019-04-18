//
// Created by 尹思维 on 2019-04-18.
//

#include "BasicEndpoint.h"

BasicEndpoint::BasicEndpoint(const sqlite::database &db, Backend *backend) : db(db), backend(backend) {}
