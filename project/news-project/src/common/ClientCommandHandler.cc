#include "ClientCommandHandler.h"
#include "MessageHandler.h"
#include <list>
#include <string>
#include "protocol.h"
#include <string>
#include <iostream>

using std::cout;
using std::list;
using std::string;
using enum Protocol;
using std::string;

/*Constructors and destructors*/
ClientCommandHandler::ClientCommandHandler(const Connection &conn) : msgh(conn) {}

/*Checks commandbyte, then executes appropriate method
according to what command is returned*/
void ClientCommandHandler::process(string input) {
    if (input == "1") {
        cout << "Newsgroups: " << "\n";
        listNewsgroups();
    }
    else if (input == "2") {
        cout << "Input newsgroup name: ";
        string name;
        std::cin >> name;
        cout << "\n";
        createNewsgroup(name);
    }
    else if (input == "3") {}
    else if (input == "4") {}
    else if (input == "5") {}
    else if (input == "6") {}
    else if (input == "7") {}
    else {
        cout << "Please provide a valid input" << "\n";
    }
};

/*Methods*/
void ClientCommandHandler::listNewsgroups() {
    msgh.sendCode(COM_LIST_NG);
    Protocol code = static_cast<Protocol>(msgh.recCode());
    if (code == ANS_LIST_NG) {
        int list_size = msgh.recInt();
        for (int i = 0; i < list_size; i++) {
            cout << msgh.recStringParameter() << "\n";
        }
    }
};
void ClientCommandHandler::createNewsgroup(string newsgroup_name) {
    msgh.sendCode(COM_CREATE_NG);
    Protocol code = static_cast<Protocol>(msgh.recCode());
    if (code == ANS_CREATE_NG) {
        msgh.sendStringParameter(newsgroup_name);
    }
};
void ClientCommandHandler::deleteNewsgroup() {};
void ClientCommandHandler::listArticles() {};
void ClientCommandHandler::createArticle() {};
void ClientCommandHandler::deleteArticle() {};
void ClientCommandHandler::getArticle() {};