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
ServerCommandHandler::ServerCommandHandler(const std::shared_ptr<Connection>& conn, MemoryDatabase* dbptr) : msgh(*conn), dbptr(dbptr) 
{}

/*Checks commandbyte, then executes appropriate method
according to what command is returned*/
void ServerCommandHandler::process(){
    Protocol code = static_cast<Protocol>(msgh.recCode());
    cout << "Received code: " << code << "\n";
    if (code == COM_LIST_NG) {
        listNewsgroups();
    }
     else if (code == COM_CREATE_NG) {
        createNewsgroup();
    } else if (code == COM_DELETE_NG) {
        deleteNewsgroup();
    } else {
        cout << code << " has no implemented function" << "\n";
    }
};

/*Methods*/
void ServerCommandHandler::listNewsgroups() {
    cout << "Sending: ANS_LIST_NG" << "\n";
    msgh.sendCode(ANS_LIST_NG);
    std::vector<Newsgroup> list = dbptr->listNewsgroups();
    cout << "Sending int: list.size() = " << list.size() << "\n";
    msgh.sendInt(list.size());
    for (Newsgroup group : list) {
        msgh.sendStringParameter(group.name);
    }
};
void ServerCommandHandler::createNewsgroup(){
    cout << "Sending: ANS_CREATE_NG" << "\n";
    msgh.sendCode(ANS_CREATE_NG);
    string newsgroup_name = msgh.recStringParameter();
    cout << "Received group name: " << newsgroup_name << "\n";
    bool status = dbptr->createNewsgroup(newsgroup_name);
    if (status == true) {
        cout << "Created newsgroup: " << newsgroup_name << "\n";
        msgh.sendCode(ANS_ACK);
    } else {
        cout << "FAILED creating newsgroup " << newsgroup_name << "\n";
        msgh.sendCode(ANS_NAK);
    }
};
void ServerCommandHandler::deleteNewsgroup(){
    cout << "Sending: ANS_DELETE_NG" << "\n";
    msgh.sendCode(ANS_DELETE_NG);
    string newsgroup_name = msgh.recStringParameter();
    cout << "Received group name: " << newsgroup_name << "\n";
    bool status = dbptr->deleteNewsgroup(newsgroup_name);
    if (status == true) {
        cout << "Deleted newsgroup: " << newsgroup_name << "\n";
        msgh.sendCode(ANS_ACK);
    } else {
        cout << "FAILED deleting newsgroup " << newsgroup_name << "\n";
        msgh.sendCode(ERR_NG_DOES_NOT_EXIST);
    }
};
void ServerCommandHandler::listArticles(){};
void ServerCommandHandler::createArticle(){};
void ServerCommandHandler::deleteArticle(){};
void ServerCommandHandler::getArticle(){};