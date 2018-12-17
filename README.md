# TestTaskSevenTest
A simple CORBA server and client in C++ (omniORB).
Client sends an array of strings to server, and receives an array of inverted strings.

You need to install omniORB to use it.

Call "make" to build the client and the server.
Run the server with "./runServer". It will print the server IOR.
Run the client with "./runClient [IOR]".
