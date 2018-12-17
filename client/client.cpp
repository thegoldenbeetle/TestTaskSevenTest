#include "client.h"
#include <vector>
#include <string>
#include <iostream>
#include "convert_utils.h"
#include "data.hh"
#include <exception>

Client::Client(int argc, char** argv) {
    
    orb = CORBA::ORB_init(argc, argv);
    obj = orb->string_to_object(argv[1]);

    dataRef = Data::Array::_narrow(obj);

    if (CORBA::is_nil(dataRef)) {
        orb->destroy();
        throw std::runtime_error("Can't narrow reference.\n");
    }   
}
    
CORBA::Short Client::sendMessage(
    const std::vector<std::string>& inputArray,
    std::vector<std::string>& outputArray) {

    StringSeq_var resultArray;    
    CORBA::Short result = dataRef->reverseStrings(vectorToSeq<StringSeq>(inputArray), resultArray);
    outputArray = secToVector<StringSeq>(resultArray); 
    
    return result;
}
    
Client::~Client() {
    orb->destroy();
}
