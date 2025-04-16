#include "ServerCommandHandler.h"
#include "MessageHandler.h"
#include <list>
#include <string>
#include <iostream>
#include "protocol.h"
#include "MemoryDatabase.h"

using std::list;
using std::string;
using std::cout;
using enum Protocol;

/*Constructors and destructors*/
ServerCommandHandler::ServerCommandHandler(const std::shared_ptr<Connection>& conn, MemoryDatabase db) : msgh(*conn), db(db) 
{}

/*Checks commandbyte, then executes appropriate method
according to what command is returned*/
void ServerCommandHandler::process(){
    Protocol code = static_cast<Protocol>(msgh.recCode());
    if (code == COM_CREATE_NG) {
        createNewsgroup();
    }
};

/*Methods*/
void ServerCommandHandler::listNewsgroups() {};
void ServerCommandHandler::createNewsgroup(){
    msgh.sendCode(ANS_CREATE_NG);
    string newsgroup_name = msgh.recStringParameter();
    db.createNewsgroup(newsgroup_name);
    cout << newsgroup_name << "\n";
};
void ServerCommandHandler::deleteNewsgroup(){};
void ServerCommandHandler::listArticles(){};
void ServerCommandHandler::createArticle(){};
void ServerCommandHandler::deleteArticle(){};
void ServerCommandHandler::getArticle(){};