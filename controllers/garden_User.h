#pragma once

#include <drogon/HttpController.h>

#include "models/User.h"

#include "bcrypt.h"

//using namespace drogon;
using CALL = std::function<void(const drogon::HttpResponsePtr &)>;

namespace garden
{
  class User_c : public drogon::HttpController<User_c>
  {
    public:
      METHOD_LIST_BEGIN
      // use METHOD_ADD to add your custom processing function here;
      // METHOD_ADD(User::get, "/{2}/{1}", Get); // path is /garden/User/{arg2}/{arg1}
      // METHOD_ADD(User::your_method_name, "/{1}/{2}/list", Get); // path is /garden/User/{arg1}/{arg2}/list
      // ADD_METHOD_TO(User::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

      METHOD_ADD(User_c::reg, "/reg?userId={1}&passwd={2}", drogon::Post);

      METHOD_LIST_END
      // your declaration of processing function maybe like this:
      // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
      // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

      auto reg(const drogon::HttpRequestPtr &req,
               CALL &&callback,
               drogon_model::sqlite3::User &&pUser) -> void const;
    private:

      struct UserWithToken {
          std::string username;
          std::string password;
          std::string token;
          explicit UserWithToken(const drogon_model::sqlite3::User &user);
          Json::Value toJson();
      };

      bool areFieldsValid(const drogon_model::sqlite3::User &user) const;
      bool isUserAvailable(const drogon_model::sqlite3::User &user, drogon::orm::Mapper<drogon_model::sqlite3::User> &mp) const;
      bool isPasswordValid(const std::string &text, const std::string &hash) const;
  };
}
