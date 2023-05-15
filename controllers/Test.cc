#include "Test.h"

// Add definition of your processing function here
auto Test::test(const drogon::HttpRequestPtr &req,
                         CALL &&callback) -> void const
{
    Json::Value ret;
    ret["result"] = "ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
