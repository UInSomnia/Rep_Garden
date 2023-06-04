#include <drogon/drogon.h>
//#include <boost/variant.hpp>

int main()
{
    //Set HTTP listener address and port
    //drogon::app().addListener("0.0.0.0",80);
    //boost::variant<int, std::string> my_var_t;
    //Load config file
    drogon::app().loadConfigFile("../config.json");
    // drogon::app().registerPostHandlingAdvice(
    //     [](const drogon::HttpRequestPtr &req, const drogon::HttpResponsePtr &resp)
    //     {
    //         LOG_DEBUG << "postHandling1";
    //         resp->addHeader("Access-Control-Allow-Origin", "*");
    //     });
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
