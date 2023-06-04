#include "tools.h"

Tools::Tools()
{

}

std::string Tools::rsa256_encrypt(const std::string &data, const std::string &key_private)
{
    const jwt::claim c(data);
    const std::string close = jwt::create()
                        .set_issuer("auth0")
					    .set_type("JWT")
					    .set_id("rsa-create")
				    	.set_payload_claim("sample", c)
				    	.sign(jwt::algorithm::rs256("", key_private, "", ""));
    return close;
}

std::string Tools::rsa256_decrypt(const std::string &data, const std::string &key_public)
{
    auto verify = jwt::verify().allow_algorithm(jwt::algorithm::rs256(key_public, "", "", "")).with_issuer("auth0");
    auto decoded = jwt::decode(data);
    verify.verify(decoded);
    // for (auto& e : decoded.get_header_json())
    //     LOG_DEBUG << 0 << e.first << " = " << e.second.to_str();
    // for (auto& e : decoded.get_payload_json())
    //     LOG_DEBUG << 1 << e.first << " = " << e.second.to_str();
    auto payload_json = decoded.get_payload_json();
    for (auto &e : payload_json)
    {
        const std::string k = e.first;
        const std::string v = e.second.to_str();
        if(k == std::string("sample"))
        {
            return v;
        }
    }
    return {};
}

bool Tools::user_validate_json_for_creation(const Json::Value &pJson, std::string &err)
{
    // +name
    // +surname
    // +patronymic
    // +phone
    // +mail
    // +password

    std::vector<std::string> fields =
    {
        std::string("name"),
        std::string("surname"),
        std::string("patronymic"),
        std::string("phone"),
        std::string("mail"),
        std::string("password")
    };

    for(const std::string &f : fields)
    {
        if(pJson.isMember(f))
        {
            const Json::Value val = pJson[f];
            if(val.isNull())
            {
                return false;
            }
            if(!val.isString())
            {
                err = "Type error in the " + f + " field";
                return false;
            }
        }
        else
        {
            err = "Field " + f + " not exist";
            return false;
        }
    }
    
    return true;
}   

bool Tools::user_validate_json_for_login(const Json::Value &pJson, std::string &err)
{
    if(const std::string name_field("login"); pJson.isMember(name_field))
    {
        const Json::Value val = pJson[name_field];
        if(val.isNull())
        {
            return false;
        }
        if(!val.isString())
        {
            err = "Type error in the " + name_field + " field";
            return false;
        }
    }
    else
    {
        err = "Field " + name_field + " not exist";
        return false;
    }

    if(const std::string name_field("password"); pJson.isMember(name_field))
    {
        const Json::Value val = pJson[name_field];
        if(val.isNull())
        {
            return false;
        }
        if(!val.isString())
        {
            err = "Type error in the " + name_field + " field";
            return false;
        }
    }
    else
    {
        err = "Field " + name_field + " not exist";
        return false;
    }

    return true;
}

bool Tools::indicator_validate_json_for_login(const Json::Value &pJson, std::string &err)
{
    // plot_number
    // plot_password
    // v1
    // v2

    std::vector<std::string> fields =
    {
        std::string("plot_number"),
        std::string("plot_password"),
        std::string("v1"),
        std::string("v2")
    };

    for(const std::string &f : fields)
    {
        if(pJson.isMember(f))
        {
            const Json::Value val = pJson[f];
            if(val.isNull())
            {
                return false;
            }
            if(!val.isString())
            {
                err = "Type error in the " + f + " field";
                return false;
            }
        }
        else
        {
            err = "Field " + f + " not exist";
            return false;
        }
    }
    
    return true;
}
