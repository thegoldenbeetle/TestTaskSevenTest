#pragma once

#include "data.hh"
#include <omniconfig.h>			

class Server : public POA_Data::Array {
public:

    inline Server() {}
    virtual ~Server() {}
    virtual CORBA::Short reverseStrings(const StringSeq& stringArray,
                                        StringSeq_out stringReversedArray);
};
