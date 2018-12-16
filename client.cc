#include "data.hh"
#include <iostream>
#include <string>
#include <vector>
#include "utils/convert_utils.h"

std::vector<std::string> readStringArray() {
    std::vector<std::string> result;
    std::string str;
    do {
        std::getline(std::cin, str);
        if (!str.empty()) 
            result.push_back(str);
    } while (!str.empty());
    return result;
}

void printStringArray(const std::vector<std::string>& array) {
    for (const std::string& str: array) {
        std::cout << str << "\n";
    }
}

static void sendMessage(Data::Array_ptr a, const std::vector<std::string>& strings) {
    StringSeq_var result = a->reverseStrings(vectorToSeq<StringSeq>(strings));
    std::cout << "Server answer:\n";
    printStringArray(secToVector<StringSeq>(result));
}

int main(int argc, char** argv) {
    try {
        
        CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

        if (argc != 2) {
            std::cerr << "Usage: client [IOR]\n";
            return 1;
        }

        CORBA::Object_var obj = orb->string_to_object(argv[1]);

        Data::Array_var dataRef = Data::Array::_narrow(obj);

        if (CORBA::is_nil(dataRef)) {
            std::cerr << "Can't narrow reference.\n";
            return 1;
        }
    
        std::cout << "\nEnter strings, enter empty string to finish input:\n";
        std::vector<std::string> strings = readStringArray();
        sendMessage(dataRef, strings);

        orb->destroy();
    }
    catch (CORBA::TRANSIENT&) {
        std::cerr << "Caught system exception TRANSIENT -- unable to contact the server.\n";
    }
    catch (CORBA::SystemException& ex) {
        std::cerr << "Caught a CORBA::" << ex._name() << "\n";
    }
    catch (CORBA::Exception& ex) {
        std::cerr << "Caught CORBA::Exception: " << ex._name() << "\n";
    }
    
    return 0;
}
