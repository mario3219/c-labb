/* myserver.cc: sample server program */
#include "connection.h"
#include "connectionclosedexception.h"
#include "server.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

/*
 * Read a string from a client.
 */
string readNumber(const std::shared_ptr<Connection>& conn)
{
        string s;
        char   ch;
        while ((ch = conn->read()) != '$') {
                s += ch;
        }
        return s;
}

/*
 * Send a string to a client.
 */
void writeString(const std::shared_ptr<Connection>& conn, const string& s)
{
        for (char c : s) {
                conn->write(c);
        }
        conn->write('$');
}

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

void process_request(std::shared_ptr<Connection>& conn)
{
        string result = readNumber(conn);
        writeString(conn, result);
}

void serve_one(Server& server)
{
        auto conn = server.waitForActivity();
        if (conn != nullptr) {
                try {
                    process_request(conn);
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

int main(int argc, char* argv[])
{
        auto server = init(argc, argv);

        while (true) {
            serve_one(server);
        }
        return 0;
}
