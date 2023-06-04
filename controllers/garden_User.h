#pragma once

#include "drogon/HttpController.h"
#include "drogon/orm/RestfulController.h"

#include "models/User.h"
#include "models/Indicator.h"

#include "bcrypt.h"
#include "tools/tools.h"

#include "OpenXLSX.hpp"

using CALL = std::function<void(const drogon::HttpResponsePtr &)>;
using USR = drogon_model::sqlite3::User;
using INDI = drogon_model::sqlite3::Indicator;

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

      METHOD_ADD(User_c::reg,             "/reg",             drogon::Post, drogon::Options);
      METHOD_ADD(User_c::login,           "/login",           drogon::Post, drogon::Options);
      METHOD_ADD(User_c::set_indicator,   "/set_indicator",   drogon::Post, drogon::Options);

      METHOD_LIST_END
      // your declaration of processing function maybe like this:
      // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
      // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

      User_c();
      auto reg(const drogon::HttpRequestPtr &req, CALL &&callback) -> void const;
      auto login(const drogon::HttpRequestPtr &req, CALL &&callback) -> void const;
      auto set_indicator(const drogon::HttpRequestPtr &req, CALL &&callback) -> void const;

    private:
      std::string key_private;
      std::string key_public;
  };
}
