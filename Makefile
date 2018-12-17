CFLAGS += -I./shared -I./utils
LIBS = -lomnithread -lomniORB4 
STUBS = shared/dataSK.cc 
STUB_HEADERS = shared/data.hh
SERVER_DIR = ./server
CLIENT_DIR = ./client

all: server client

$(STUBS): data.idl
	omniidl -bcxx data.idl
	mkdir shared
	mv dataSK.cc data.hh shared/

server: $(SERVER_DIR)/runServer.cpp $(STUBS)
	g++ $(CFLAGS) -o runServer $(LIBS) $(SERVER_DIR)/server.cpp $(STUBS) $(SERVER_DIR)/runServer.cpp

client: $(CLIENT_DIR)/runClient.cpp $(STUBS)
	g++ $(CFLAGS) -o runClient $(LIBS) $(CLIENT_DIR)/client.cpp $(STUBS) $(CLIENT_DIR)/runClient.cpp

clean:
	rm -f runClient runServer $(STUBS) $(STUB_HEADERS)
