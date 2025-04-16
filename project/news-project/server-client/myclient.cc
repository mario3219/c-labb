/* myclient.cc: sample client program */
#include "connection.h"
#include "connectionclosedexception.h"
#include "CommandHandler.h"
#include "protocol.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using enum Protocol;

/* Client Methods */

void writeUI() {
      /*
        Text-based UI for user inputs
        */
        cout << "1. List news groups\n";
        cout << "2. Create newsgroup\n";
        cout << "3. Delete newsgroup\n";
        cout << "4. List articles\n";
        cout << "5. Create article\n";
        cout << "6. Delete article\n";
        cout << "7. Get article\n";
        cout << "--------\nInput: ";
}

/* --------------------------------------Client runtime--------------------------------------------*/

int app(const Connection& conn)
{

        bool RUNTIME = true;    // set to false if the user wants to exit
        string usr_input;
        //CommandHandler cmdh(conn);

        cout << "Welcome to our server! Please write the number to the corresponding alternative:\n" << "--------\n";
        writeUI();
        while (RUNTIME && cin >> usr_input) {
                /* Input client methods here */
                try {
                        /* SUGGESTED FORMAT
                        cmdh.process();
                        */
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
