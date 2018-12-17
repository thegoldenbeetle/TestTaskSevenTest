#pragma once

#include <string>
#include <vector>
#include "data.hh"

class Client {
public:

    Client(int argc, char** argv);

    CORBA::Short sendMessage(
        const std::vector<std::string>& inputArray,
        std::vector<std::string>& outputArray);

    ~Client();

private:

    CORBA::ORB_var orb;
    CORBA::Object_var obj;
    Data::Array_var dataRef;        

};
