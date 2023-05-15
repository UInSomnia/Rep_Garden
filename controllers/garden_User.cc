#include "garden_User.h"

// using namespace garden;

// Add definition of your processing function here

// https://github.com/maikeulb/orgChartApi/blob/master/controllers/AuthController.cc

namespace drogon
{
    template <>
    inline drogon_model::sqlite3::User fromRequest(const drogon::HttpRequest &req)
    {
        auto jsonPtr = req.getJsonObject();
        auto json = *jsonPtr;
        auto user = drogon_model::sqlite3::User(json);
        return user;
    }
}

auto garden::User_c::reg(const drogon::HttpRequestPtr &req,
                         CALL &&callback,
                         drogon_model::sqlite3::User &&pUser) -> void const
{
    LOG_DEBUG << "register new User ";

    try
    {
        auto dbClientPtr = drogon::app().getDbClient();
        drogon::orm::Mapper<drogon_model::sqlite3::User> mp(dbClientPtr);

        if (!areFieldsValid(pUser))
        {
            Json::Value ret{};
            ret["error"] = "missing fields";
            auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
            callback(resp);
            return;
        }
        if (!isUserAvailable(pUser, mp))
        {
            Json::Value ret{};
            ret["error"] = "username is taken";
            auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
            callback(resp);
            return;
        }

        drogon_model::sqlite3::User newUser = pUser;
        newUser.setPassword(bcrypt::generateHash(newUser.getValueOfPassword()));
        mp.insertFuture(newUser).get();

        auto userWithToken = garden::User_c::UserWithToken(newUser);
        Json::Value ret = userWithToken.toJson();
        auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::HttpStatusCode::k201Created);
        callback(resp);
    }
    catch (const drogon::orm::DrogonDbException &e)
    {
        LOG_ERROR << e.base().what();
        Json::Value ret{};
        ret["error"] = "database error";
        auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
        callback(resp);
    }

    // std::string password0 = "top_secret";

    // std::string hash = bcrypt::generateHash(password0);

    // Json::Value ret;
    // ret["result"] = "ok";
    // ret["userId"] = userId;
    // ret["psswd"] = password;
    // ret["hash_psswd"] = hash;
    // //ret["token"] = drogon::utils::getUuid();
    // auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
    // callback(resp);
}

bool garden::User_c::areFieldsValid(const drogon_model::sqlite3::User &user) const
{
    return user.getName() != nullptr && user.getPassword() != nullptr;
}

bool garden::User_c::isUserAvailable(const drogon_model::sqlite3::User &user, drogon::orm::Mapper<drogon_model::sqlite3::User> &mp) const
{
    auto criteria = drogon::orm::Criteria(drogon_model::sqlite3::User::Cols::_name, drogon::orm::CompareOperator::EQ, user.getValueOfName());
    return mp.findFutureBy(criteria).get().empty();
}

bool garden::User_c::isPasswordValid(const std::string &text, const std::string &hash) const
{
    return bcrypt::validatePassword(text, hash);
}

garden::User_c::UserWithToken::UserWithToken(const drogon_model::sqlite3::User &user)
{
    // auto *jwtPtr = drogon::app().getPlugin<JwtPlugin>();
    // auto jwt = jwtPtr->init();
    // token = jwt.encode("user_id", user.getValueOfId());
    // username = user.getValueOfUsername();
}

Json::Value garden::User_c::UserWithToken::toJson()
{
    Json::Value ret{};
    ret["username"] = username;
    ret["token"] = token;
    return ret;
}
