//
// Created by 尹思维 on 2019-04-16.
//

#ifndef BACKEND_ABSTRACTREQUESTENDPOINT_H
#define BACKEND_ABSTRACTREQUESTENDPOINT_H

#include "./common.h"

#define BEGIN_HANDLE(action) try { if(req.msg.actionName == (action)) {
#define THEN_HANDLE(action) return true;} else if (req.msg.actionName == (action)) {
#define END_HANDLE return true;} else {return false;} } catch(exception &e) {NOTIFY_ERR(req.msg.actionName,e.what());}
#define PARAM(i) (req.msg.params[(i)])
#define NOTIFY(_query)  NOTIFY_WITH((req.msg.actionName),_query)

#define NOTIFY_WITH(_eventName, query) do{ \
    vector<vector<string>>  _r;\
    db << query >> _r; \
    responses.push_back({.session = req.session,.msg = {.eventName = (_eventName) ,.rows=_r,.errmsg=""}});\
}while(0)
#define NOTIFY_ERR(_eventName, _errmsg) do{ \
    responses.push_back({.session = req.session,.msg = {.eventName = (_eventName) ,.rows={},.errmsg=(_errmsg)}});\
}while(0)

class AbstractRequestEndpoint {
    virtual bool handle(RequestMessage &req, vector<ResponseMessage> &responses) = 0;
};


#endif //PROJECT_ABSTRACTREQUESTENDPOINT_H
