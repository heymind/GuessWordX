//
// Created by 尹思维 on 2019-04-16.
//

#ifndef BACKEND_COMMON_H
#define BACKEND_COMMON_H

#include <functional>
#include <vector>

#include "sqlite_modern_cpp.h"

#include "../transports/common.h"

typedef ServerSideResponseMessage ResponseMessage;

typedef ServerSideRequestMessage RequestMessage;
using namespace std;

//typedef function<vector<ResponseMessage>,ServerSideRequestMessage> DispatchReveiver;

#endif //BACKEND_COMMON_H
