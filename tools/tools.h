#pragma once

#include <string>
#include <vector>

#include "json/json.h"
#include "jwt-cpp/jwt.h"

class Tools
{
public:
    Tools();

    static std::string rsa256_encrypt(const std::string &data, const std::string &key_private);
    static std::string rsa256_decrypt(const std::string &data, const std::string &key_public);

    static bool user_validate_json_for_creation(const Json::Value &pJson, std::string &err);
    static bool user_validate_json_for_login(const Json::Value &pJson, std::string &err);

    static bool indicator_validate_json_for_login(const Json::Value &pJson, std::string &err);
};
