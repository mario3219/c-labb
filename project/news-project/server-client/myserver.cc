/* myserver.cc: sample server program */
#include "connection.h"
#include "connectionclosedexception.h"
#include "server.h"
#include "MessageHandler.h"
<<<<<<< HEAD
#include "protocol.h"
// Update the include path to the correct relative or absolute path
#include "../include/MemoryDatabase.h"
=======
#include "ServerCommandHandler.h"
#include "MemoryDatabase.h"
>>>>>>> test-commandhandler

#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

/* --------------------------------------Server methods--------------------------------------------*/

int readNumber(const std::shared_ptr<Connection> &conn) { return 0; }

void writeString(const std::shared_ptr<Connection> &conn, const string &s) {}

void listNewsgroups(const std::shared_ptr<Connection> &conn, const string &s, MemoryDatabase db)
{
        auto newsgroups = db.listNewsgroups();
        for (const auto &newsgroup : newsgroups)
        {
                cout << "Newsgroup: " << newsgroup.name << endl;
        }
}

void createNewsgroup(const std::shared_ptr<Connection> &conn, const string &s, MemoryDatabase db, string name)
{
        if (db.createNewsgroup(name))
        {
                cout << "Newsgroup created: " << name << endl;
        }
        else
        {
                cout << "Failed to create newsgroup: " << name << endl;
        }
}

void deleteNewsgroup(const std::shared_ptr<Connection> &conn, const string &s, MemoryDatabase db, string name)
{
        if (db.deleteNewsgroup(name))
        {
                cout << "Newsgroup deleted: " << name << endl;
        }
        else
        {
                cout << "Failed to delete newsgroup: " << name << endl;
        }
}

void listArticles(const std::shared_ptr<Connection> &conn, const string &s, MemoryDatabase db, string newsgroup_name)
{
        auto articles = db.listArticles(newsgroup_name);
        for (const auto &article : articles)
        {
                cout << "Article ID: " << article.id << ", Title: " << article.title << endl;
        }
}

/* --------------------------------------Server runtime--------------------------------------------*/

<<<<<<< HEAD
void serve_one(Server &server, MemoryDatabase db)
{
        auto conn = server.waitForActivity();
        if (conn != nullptr)
        {
                try
                {
                        MessageHandler msgh(*conn);

                        Protocol command = static_cast<Protocol>(msgh.recCode());

                        switch (command)
                        {
                        case Protocol::COM_LIST_NG:
                                listNewsgroups(conn, "list", db);
                                break;
                        case Protocol::COM_CREATE_NG:
                        {
                                string name = msgh.recStringParameter();
                                createNewsgroup(conn, "create", db, name);
                                msgh.sendCode(Protocol::ANS_CREATE_NG);
                        }
                                /* Server commands
                                Suggested format:
                                command = conn.read()
                                if command = LIST_GROUPS
                                        Commandhander.writeList(list)
                                if command = SIZE_LIST
                                        commandhandler.writesize(size)
                                ...
                                */
                        }
                } // Close the switch statement
                catch (ConnectionClosedException &)
                {
=======
void serve_one(Server& server, MemoryDatabase database)
{
        auto conn = server.waitForActivity();
        ServerCommandHandler cmdh(conn,database);
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
>>>>>>> test-commandhandler
                        server.deregisterConnection(conn);
                        cout << "Client closed connection" << endl;
                }
        }
        else
        {
                conn = std::make_shared<Connection>();
                server.registerConnection(conn);
                cout << "New client connects" << endl;
        }
}

/* --------------------------------------Server initializers - don't touch--------------------------------------------*/

Server init(int argc, char *argv[])
{
        if (argc != 2)
        {
                cerr << "Usage: myserver port-number" << endl;

                exit(1);
        }

        int port = -1;
        try
        {
                port = std::stoi(argv[1]);
        }
        catch (std::exception &e)
        {
                cerr << "Wrong format for port number. " << e.what() << endl;
                exit(2);
        }

        Server server(port);
        if (!server.isReady())
        {
                cerr << "Server initialization error." << endl;
                exit(3);
        }
        return server;
}

int main(int argc, char *argv[])
{
        auto db = MemoryDatabase();
        auto server = init(argc, argv);

<<<<<<< HEAD
        while (true)
        {
                serve_one(server, db);
=======
        MemoryDatabase database;

        while (true) {
            serve_one(server,database);
>>>>>>> test-commandhandler
        }
        return 0;
}
