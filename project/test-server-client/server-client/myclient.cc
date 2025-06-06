/* myclient.cc: sample client program */
#include "connection.h"
#include "connectionclosedexception.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
/*
 * Send a string to the server
 */
void writeString(const Connection& conn, string str)
{
        for (char c : str) {
             conn.write(c);   
        }
        conn.write('$'); // marks end of message
}

/*
 * Read a string from the server.
 */
string readString(const Connection& conn)
{
        string s;
        char   ch;
        while ((ch = conn.read()) != '$') {
                s += ch;
        }
        return s;
}

/* Creates a client for the given args, if possible.
 * Otherwise exits with error code.
 */
Connection init(int argc, char* argv[])
{
        if (argc != 3) {
                cerr << "Usage: myclient host-name port-number" << endl;
                exit(1);
        }

        int port = -1;
        try {
                port = std::stoi(argv[2]);
        } catch (std::exception& e) {
                cerr << "Wrong port number. " << e.what() << endl;
                exit(2);
        }

        Connection conn(argv[1], port);
        if (!conn.isConnected()) {
                cerr << "Connection attempt failed" << endl;
                exit(3);
        }

        return conn;
}

int app(const Connection& conn)
{
        cout << "Type a string: ";
        string str;

        while (cin >> str) {
                try {
                        cout << str << " is ...";
                        writeString(conn, str);
                        string reply = readString(conn);
                        cout << " " << reply << endl;
                        cout << "Type another string: ";
                } catch (ConnectionClosedException&) {
                        cout << " no reply from server. Exiting." << endl;
                        return 1;
                }
        }
        cout << "\nexiting.\n";
        return 0;
}

int main(int argc, char* argv[])
{
        Connection conn = init(argc, argv);
        return app(conn);
}
