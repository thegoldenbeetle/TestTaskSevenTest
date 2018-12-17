#include <iostream>
#include <string>
#include <vector>
#include "client.h"

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

int main(int argc, char** argv) {
    try {
        
        if (argc != 2) {
            std::cerr << "Usage: runClient [IOR]\n";
            return 1;
        }
        
        std::cout << "\nEnter strings, enter empty string to finish input:\n";
        std::vector<std::string> strings = readStringArray();

        Client client(argc, argv);
        
        std::vector<std::string> resultStrings;
        if (client.sendMessage(strings, resultStrings) == 1) {
            std::cout << "Array with reversed strings:\n";
            printStringArray(resultStrings);
        } else {
            std::cout << "Bad answer from server\n";
        };

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
    catch (std::exception& ex) {
        std::cerr << "Caught std::exception: " << ex.what() << "\n";
    }
    
    return 0;
}
