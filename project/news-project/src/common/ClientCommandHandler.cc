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
    if (input == "1") {}
    if (input == "2") {
        cout << "Input newsgroup name: ";
        string name;
        std::cin >> name;
        cout << "\n";
        createNewsgroup(name);
    }
    if (input == "3") {}
    if (input == "4") {}
    if (input == "5") {}
    if (input == "6") {}
    if (input == "7") {}
};

/*Methods*/
void ClientCommandHandler::listNewsgroups() {

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