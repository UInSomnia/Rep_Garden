#include "garden_User.h"

// using namespace garden;

// Add definition of your processing function here

// https://github.com/maikeulb/orgChartApi/blob/master/controllers/AuthController.cc

garden::User_c::User_c()
{
    key_public = std::string(R"(-----BEGIN PUBLIC KEY-----
MIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEA5kbZMY/I+pz6eT4833Fz
BHwA3L+40lR+oYgjCs3Nsxys/1Z5ffMj8tYRz/VbrBNbwHl0glIocNnOux8OyZzt
Z3/Z2egNqo6f6tkr1ZqB5KO1Wns9iKv3prNzu/ffCOLbsvwMmyj66YpCH8k4sirV
7xBpnPFZi8SDO+blf7FumSq7w1KSMnQdEeYJ82HQdvG2IvoJwI9qi4E/DAP7BmCh
+Dw887XVjReDiJ34gkDFEHfJyrh7fRoDksPxw2y+sUnY/1wD0XyTSIHGY5HxApXD
h4Wz/ZLSVsyWpMPLwzyfJxW0XEpsYJjDDNOJBHJAeqVNcXyKbuBRTyGeCmutl7Ui
o9KiDquQzlz5kzVVHuVmgYzi/tlLliAGitZcENiAiosWZEmqhZ47HUuLyrL3QotM
7GsyBip7zrHCVTvnIHbXEvqibmQaY4TZPfW7T0m/2h1KDj7MOpj6shuiOf5i/S2J
jMvc47cgi3l8kijv//n2ezuMT1jxaNjGw2zys2OqhU0AU4jFpxdWhYCxrX7uQJoE
y0yIg0lKJl/dk/H4dP+RfEwbEzkOuLlDKeBUwXe6T4JhwHG/lk8m08p1oGsJHjcP
uynvVcpMCcwDw5+qAaqBVItEw/qVJWQK5e/YXlqLpeuDfVElrshnouwgJnJNm5G9
zLr4mHTHCdNE+YtCiKWQTmcCAwEAAQ==
-----END PUBLIC KEY-----)");
    key_private = std::string(R"(-----BEGIN RSA PRIVATE KEY-----
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
-----END RSA PRIVATE KEY-----)");
}

auto garden::User_c::reg(const drogon::HttpRequestPtr &req, CALL &&callback) -> void const
{
    // +name
    // +surname
    // +patronymic
    // +phone
    // +mail
    // +password

    LOG_DEBUG << "Enter reg()";
    auto jsonPtr = req->jsonObject();
    Json::Value &req_json = *jsonPtr;
    auto &origin = req->getHeader("Origin");
    auto callbackPtr = std::make_shared<CALL>(std::move(callback));



    // // boost::gregorian::date xGPWStart(1941, boost::gregorian::Jun, 22);
    // boost::gregorian::date   date_now = boost::gregorian::day_clock::local_day();
    // boost::posix_time::ptime time_now = boost::posix_time::second_clock::local_time();

    // const std::locale date_fmt(std::locale::classic(), new boost::gregorian::date_facet("%d.%m.%Y"));
    // boost::posix_time::time_facet *const time_fmt = new boost::posix_time::time_facet("%H:%M:%S");
    // // const std::string str_xGPWStart = date_to_string(xGPWStart, fmt);
    // const std::string str_date_now = date_to_string(date_now, date_fmt);
    // const std::string str_time_now = time_to_string(time_now, time_fmt);

    // Json::Value ret;
    // ret["str_date_now"] = str_date_now;
    // ret["str_time_now"] = str_time_now;
    // auto resp= drogon::HttpResponse::newHttpJsonResponse(ret);
    // resp->setStatusCode(drogon::k200OK);
    // resp->addHeader("Access-Control-Allow-Origin", origin);
    // return (*callbackPtr)(resp);



    if(!jsonPtr)
    {
        Json::Value ret;
        ret["error"]="No json object is found in the request";
        auto resp= drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", origin);
        return (*callbackPtr)(resp);
    }

    if(std::string err; !Tools::user_validate_json_for_creation(req_json, err))
    {
        Json::Value ret;
        ret["error"] = err;
        auto resp= drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", origin);
        return (*callbackPtr)(resp);
    }

    try 
    {
        // {
        //     OpenXLSX::XLDocument doc;
        //     doc.create("test_excel_file.xlsx");
        //     auto wbk = doc.workbook();
        //     wbk.addWorksheet("Sheet_text");
        //     // wbk.worksheet("Sheet_text").setActive();
        //     auto wks = doc.workbook().worksheet("Sheet_text");

        //     wks.cell("A1").value() = "Hello, OpenXLSX!";
        //     wks.cell("B1").value() = 240;

        //     doc.save();
        //     doc.close();
        // }

        {
            const std::string open = req_json["name"].asString();
            req_json["name"] = Tools::rsa256_encrypt(open, key_private);
        }
        // const std::string decode = Tools::rsa256_decrypt(req_json["mail"].asString(), key_public);
        // LOG_DEBUG << "result decode = " << decode;
        {
            const std::string open = req_json["surname"].asString();
            req_json["surname"] = Tools::rsa256_encrypt(open, key_private);
        }
        {
            const std::string open = req_json["patronymic"].asString();
            req_json["patronymic"] = Tools::rsa256_encrypt(open, key_private);
        }
        {
            const std::string open = req_json["phone"].asString();
            req_json["phone"] = Tools::rsa256_encrypt(open, key_private);
        }
        {
            const std::string open = req_json["mail"].asString();
            req_json["mail"] = Tools::rsa256_encrypt(open, key_private);
        }

        {
            const std::string password_open = req_json["password"].asString();
            const std::string password_close = bcrypt::generateHash(password_open);
            req_json["password"] = password_close;
        }

        req_json["id_role"]   = 0;
        req_json["is_banned"] = 0;

        USR object = USR(req_json);
        auto dbClientPtr = drogon::app().getDbClient();
        drogon::orm::Mapper<USR> mapper(dbClientPtr);
        mapper.insert(
            object,
            [callbackPtr, &origin](USR newObject)
            {
                Json::Value ret;
                auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(drogon::k201Created);
                resp->addHeader("Access-Control-Allow-Origin", origin);
                (*callbackPtr)(resp);
            },
            [callbackPtr, &origin](const drogon::orm::DrogonDbException &e)
            {
                LOG_ERROR << e.base().what();
                Json::Value ret;
                ret["error"] = "database error";
                auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(drogon::k500InternalServerError);
                resp->addHeader("Access-Control-Allow-Origin", origin);
                (*callbackPtr)(resp);   
            });
    }
    catch(const Json::Exception &e)
    {
        LOG_ERROR << e.what();
        Json::Value ret;
        ret["error"] = "Field insert object";
        auto resp= drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", origin);
        return (*callbackPtr)(resp);     
    }   
}

auto garden::User_c::login(const drogon::HttpRequestPtr &req, CALL &&callback) -> void const
{
    // name
    // surname
    // patronymic
    // +phone
    // +mail
    // +password

    //JSON req:
    //login (phone or mail)
    //password

    LOG_DEBUG << "Enter reg()";
    auto jsonPtr = req->jsonObject();
    Json::Value &req_json = *jsonPtr;
    auto &origin = req->getHeader("Origin");
    auto callbackPtr = std::make_shared<CALL>(std::move(callback));
    
    if(!jsonPtr)
    {
        Json::Value ret;
        ret["error"] = "No json object is found in the request";
        auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", origin);
        return (*callbackPtr)(resp);
    }

    if(std::string err; !Tools::user_validate_json_for_login(req_json, err))
    {
        Json::Value ret;
        ret["error"] = err;
        auto resp= drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", origin);
        return (*callbackPtr)(resp);
    }

    try 
    {
        {
            const std::string login_open = req_json["login"].asString();
            const std::string login_close = Tools::rsa256_encrypt(login_open, key_private);
            req_json["mail"]  = login_close;
            req_json["phone"] = login_close;
        }
        
        USR object = USR(req_json);
        auto dbClientPtr = drogon::app().getDbClient();
        drogon::orm::Mapper<USR> mapper(dbClientPtr);
        const std::vector<USR> users = mapper.findBy(
            drogon::orm::Criteria("mail", drogon::orm::CompareOperator::EQ, req_json["mail"].asString()) ||
            drogon::orm::Criteria("phone", drogon::orm::CompareOperator::EQ, req_json["phone"].asString()));

        Json::Value ret;
        if(users.empty())
        {
            ret["message"] = "Login or password failed";
            auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(drogon::k401Unauthorized);
            resp->addHeader("Access-Control-Allow-Origin", origin);
            return (*callbackPtr)(resp);
        }
        else if(users.size() != 1)
        {
            ret["message"] = "Login or password failed";
            auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(drogon::k400BadRequest);
            resp->addHeader("Access-Control-Allow-Origin", origin);
            return (*callbackPtr)(resp);
        }

        const USR &user_find_db = users[0];
        const std::string password_find_db = *(user_find_db.getPassword());
        const std::string password_req = req_json["password"].asString();
        if(!bcrypt::validatePassword(password_req, password_find_db))
        {
            ret["message"] = "Login or password failed";
            auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(drogon::k401Unauthorized);
            resp->addHeader("Access-Control-Allow-Origin", origin);
            return (*callbackPtr)(resp);
        }

        {
            // name
            // surname
            // patronymic
            // +phone
            // +mail
            // +password
            {
                const std::string close = *(user_find_db.getName());
                ret["user_db_name"] = Tools::rsa256_decrypt(close, key_public);
            }
            {
                const std::string close = *(user_find_db.getSurname());
                ret["user_db_surname"] = Tools::rsa256_decrypt(close, key_public);
            }
            {
                const std::string close = *(user_find_db.getPatronymic());
                ret["user_db_patronymic"] = Tools::rsa256_decrypt(close, key_public);
            }
            {
                const std::string close = *(user_find_db.getPhone());
                ret["user_db_phone"] = Tools::rsa256_decrypt(close, key_public);
            }
            {
                const std::string close = *(user_find_db.getMail());
                ret["user_db_mail"] = Tools::rsa256_decrypt(close, key_public);
            }
            ret["message"] = "Success";

            //Set cookies or session start
            auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(drogon::k200OK);
            resp->addHeader("Access-Control-Allow-Origin", origin);
            return (*callbackPtr)(resp);
        }
    }
    catch(const Json::Exception &e)
    {
        LOG_ERROR << e.what();
        Json::Value ret;
        ret["error"] = "Field login";
        auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", origin);
        return (*callbackPtr)(resp);
    }
}

auto garden::User_c::set_indicator(const drogon::HttpRequestPtr &req, CALL &&callback) -> void const
{

    // plot_number
    // plot_password
    // v1
    // v2
    
    auto jsonPtr = req->jsonObject();
    Json::Value &req_json = *jsonPtr;
    auto &origin = req->getHeader("Origin");
    auto callbackPtr = std::make_shared<CALL>(std::move(callback));

    if(!jsonPtr)
    {
        Json::Value ret;
        ret["error"] = "No json object is found in the request";
        auto resp= drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", origin);
        return (*callbackPtr)(resp);
    }

    if(std::string err; !Tools::indicator_validate_json_for_login(req_json, err))
    {
        Json::Value ret;
        ret["error"] = err;
        auto resp= drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", origin);
        return (*callbackPtr)(resp);
    }

    try 
    {
        const std::string plot_number    = req_json["plot_number"].asString();
        const std::string plot_password  = req_json["plot_password"].asString();
        const std::string v1             = req_json["v1"].asString();
        const std::string v2             = req_json["v2"].asString();

        bool ok_v1 = false;
        const int32_t num_v1             = string_to_int(v1, ok_v1);
        bool ok_v2 = false;
        const int32_t num_v2             = string_to_int(v2, ok_v2);
        if(!ok_v1 || !ok_v2)
        {
            Json::Value ret;
            ret["error"] = "v1 or v2 can't convert to integer";
            auto resp= drogon::HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(drogon::k400BadRequest);
            resp->addHeader("Access-Control-Allow-Origin", origin);
            return (*callbackPtr)(resp);  
        }

        const boost::gregorian::date   date_now = boost::gregorian::day_clock::local_day();
        const boost::posix_time::ptime time_now = boost::posix_time::second_clock::local_time();
        const tm tm_time_now = boost::posix_time::to_tm(time_now);

        const int16_t year      = date_now.year();
        const int16_t month     = date_now.month();
        const int16_t day       = date_now.day();
        const int16_t hour      = tm_time_now.tm_hour;
        const int16_t minute    = tm_time_now.tm_min;
        const int16_t second    = tm_time_now.tm_sec;

        Json::Value json_indicator;
        json_indicator["id_counter"]    = 1;
        json_indicator["year"]          = year;
        json_indicator["month"]         = month;
        json_indicator["day"]           = day;
        json_indicator["hour"]          = hour;
        json_indicator["minute"]        = minute;
        json_indicator["second"]        = second;
        json_indicator["T1"]            = num_v1;
        json_indicator["T2"]            = num_v2;

        // auto resp = drogon::HttpResponse::newHttpJsonResponse(json_indicator);
        // resp->setStatusCode(drogon::k201Created);
        // resp->addHeader("Access-Control-Allow-Origin", origin);
        // return (*callbackPtr)(resp);

        INDI object = INDI(json_indicator);
        auto dbClientPtr = drogon::app().getDbClient();
        drogon::orm::Mapper<INDI> mapper(dbClientPtr);
        mapper.insert(
            object,
            [callbackPtr, &origin](INDI newObject)
            {
                Json::Value ret;
                auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(drogon::k201Created);
                resp->addHeader("Access-Control-Allow-Origin", origin);
                (*callbackPtr)(resp);
            },
            [callbackPtr, &origin](const drogon::orm::DrogonDbException &e)
            {
                LOG_ERROR << e.base().what();
                Json::Value ret;
                ret["error"] = "database error";
                auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(drogon::k500InternalServerError);
                resp->addHeader("Access-Control-Allow-Origin", origin);
                (*callbackPtr)(resp);   
            });
    }
    catch(const Json::Exception &e)
    {
        LOG_ERROR << e.what();
        Json::Value ret;
        ret["error"] = "Field insert object";
        auto resp= drogon::HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", origin);
        return (*callbackPtr)(resp);     
    }
}

auto garden::User_c::date_to_string(const boost::gregorian::date& date, const std::locale &fmt) -> std::string
{
    std::ostringstream os;
    os.imbue(fmt);
    os << date;
    return os.str();
}

auto garden::User_c::time_to_string(const boost::posix_time::ptime& time, boost::posix_time::time_facet *const fmt) -> std::string
{
    std::ostringstream msg;
    msg.imbue(std::locale(msg.getloc(), fmt));
    msg << time;
    return msg.str();
}

auto garden::User_c::string_to_int(const std::string &str, bool &ok) -> int32_t
{
    ok = false;
    size_t pos = -1;
    int32_t result = -1;
    try
    {
        result = std::stoi(str, &pos);
    }
    catch(const std::exception& e)
    {
        ok = false;
        return -1;
    }
    const int32_t len = str.length();
    if(pos != len)
    {
        ok = false;
        return -1;
    }

    ok = true;
    return result;
}
