#include "server.h"
#include <string>
#include <vector>
#include <algorithm>
#include "convert_utils.h"

CORBA::Short Server::reverseStrings(const StringSeq& stringArray, 
                                      StringSeq_out stringReversedArray) {
    std::vector<std::string> strings = secToVector<StringSeq>(stringArray);
    
    for (std::string& str: strings) {
        std::reverse(begin(str), end(str));
    }
    
    StringSeq* result = new StringSeq(vectorToSeq<StringSeq>(strings));
    stringReversedArray = result;    
    
    return 1;
}

