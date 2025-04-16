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

/*Constructors and destructors*/
ClientCommandHandler::ClientCommandHandler(const Connection &conn) : msgh(conn) {}

/*Checks commandbyte, then executes appropriate method
according to what command is returned*/
void ClientCommandHandler::process(string input) {
    if (input == "1") {listNewsgroups();}
    if (input == "2") {}
    if (input == "3") {}
    if (input == "4") {}
    if (input == "5") {}
    if (input == "6") {}
    if (input == "7") {}
};

/*Methods*/
void ClientCommandHandler::listNewsgroups() {
    
};
void ClientCommandHandler::createNewsgroup() {};
void ClientCommandHandler::deleteNewsgroup() {};
void ClientCommandHandler::listArticles() {};
void ClientCommandHandler::createArticle() {};
void ClientCommandHandler::deleteArticle() {};
void ClientCommandHandler::getArticle() {};