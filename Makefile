LIBS = -lomnithread -lomniORB4 
STUBS = dataSK.cc 
STUB_HEADERS = data.hh

all: server client

$(STUBS): data.idl
	omniidl -bcxx data.idl

server: server.cc $(STUBS)
	g++ -o server $(LIBS) server.cc $(STUBS)

client: client.cc $(STUBS)
	g++ -o client $(LIBS) client.cc $(STUBS)

clean:
	rm -f client server $(STUBS) $(STUB_HEADERS)
