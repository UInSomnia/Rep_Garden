#include <drogon/drogon.h>
//#include <boost/variant.hpp>

int main()
{
    //Set HTTP listener address and port
    //drogon::app().addListener("0.0.0.0",80);
    //boost::variant<int, std::string> my_var_t;
    //Load config file
    drogon::app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
