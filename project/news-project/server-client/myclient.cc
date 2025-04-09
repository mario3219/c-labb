/* myclient.cc: sample client program */
#include "connection.h"
#include "connectionclosedexception.h"
#include "CommandHandler.h"
#include "MessageHandler.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

/* Client Methods */

void write(const Connection& conn, int value) {}

string read(const Connection& conn) {return "empty";}

/* --------------------------------------Client runtime--------------------------------------------*/

int app(const Connection& conn)
{
        /*
        Insert text-based UI for user inputs
        */

        cout << "Welcome to our server! Sorry, it is under development\n";

        bool RUNTIME = true;    // set to false if the user wants to exit
        string usr_input;

        while (RUNTIME || cin >> usr_input) {
                /* Input client methods here */
                try {
                        /* SUGGESTED FORMAT
                        if (usr_input == "list groups") {
                                commandhandler.getArticles
                        }
                        */
                        cout << "No available methods so far\n";
                        RUNTIME = false;
                /* Closed connection handler */
                } catch (ConnectionClosedException&) {
                        cout << " no reply from server. Exiting." << endl;
                        return 1;
                }
        }
        cout << "\nexiting.\n";
        return 0;
}

/* --------------------------------------Client initializers - don't touch--------------------------------------------*/

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

int main(int argc, char* argv[])
{
        Connection conn = init(argc, argv);
        return app(conn);
}
