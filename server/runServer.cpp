#include "server.h"
#include <iostream>

int main(int argc, char** argv) {
    
    try {
               
        CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);
        CORBA::Object_var obj = orb->resolve_initial_references("RootPOA");
        PortableServer::POA_var poa = PortableServer::POA::_narrow(obj);

        PortableServer::Servant_var<Server> server = new Server();

        poa->activate_object(server);

        CORBA::String_var sior(orb->object_to_string(server->_this()));
        std::cout << sior << "\n";

        PortableServer::POAManager_var pman = poa->the_POAManager();
        pman->activate();

        orb->run();
        
        orb->destroy();	
    }
    catch (CORBA::SystemException& ex) {
        std::cerr << "Caught CORBA::" << ex._name() << "\n";
    }
    catch (CORBA::Exception& ex) {
        std::cerr << "Caught CORBA::Exception: " << ex._name() << "\n";
    }
    return 0;
}
