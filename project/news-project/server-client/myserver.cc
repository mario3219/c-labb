#include "connection.h"
#include "connectionclosedexception.h"
#include "server.h"
#include "MessageHandler.h"
#include "ServerCommandHandler.h"
#include "MemoryDatabase.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

/* --------------------------------------Server methods--------------------------------------------*/

//int readNumber(const std::shared_ptr<Connection>& conn) {return 0;}

//void writeString(const std::shared_ptr<Connection>& conn, const string& s) {}

/* --------------------------------------Server runtime--------------------------------------------*/

void serve_one(Server& server, MemoryDatabase* dbptr)
{
        auto conn = server.waitForActivity();
        ServerCommandHandler cmdh(conn, dbptr);
        if (conn != nullptr) {
                try {
                        cmdh.process();

                        /* Server commands
                        Suggested format: 
                        command = conn.read()
                        if command = LIST_GROUPS
                                Commandhander.writeList(list)
                        if command = SIZE_LIST
                                commandhandler.writesize(size)
                        ...
                        */
                } catch (ConnectionClosedException&) {
                        server.deregisterConnection(conn);
                        cout << "Client closed connection" << endl;
                }
        } else {
                conn = std::make_shared<Connection>();
                server.registerConnection(conn);
                cout << "New client connects" << endl;
        }
}

/* --------------------------------------Server initializers - don't touch--------------------------------------------*/

Server init(int argc, char* argv[])
{
        if (argc != 2) {
                cerr << "Usage: myserver port-number" << endl;
                exit(1);
        }

        int port = -1;
        try {
                port = std::stoi(argv[1]);
        } catch (std::exception& e) {
                cerr << "Wrong format for port number. " << e.what() << endl;
                exit(2);
        }

        Server server(port);
        if (!server.isReady()) {
                cerr << "Server initialization error." << endl;
                exit(3);
        }
        return server;
}

int main(int argc, char* argv[])
{
        auto server = init(argc, argv);
        MemoryDatabase db;
        MemoryDatabase* dbptr = &db;

        while (true) {
            serve_one(server,dbptr);
        }
        return 0;
}
