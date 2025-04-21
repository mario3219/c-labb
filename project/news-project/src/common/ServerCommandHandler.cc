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
    cout << "---Waiting for new request---" << "\n";
    Protocol code = static_cast<Protocol>(msgh.recCode());
    cout << "Received code: " << code << "\n";
    if (code == COM_LIST_NG) {
        listNewsgroups();
    } else if (code == COM_CREATE_NG) {
        createNewsgroup();
    } else if (code == COM_DELETE_NG) {
        deleteNewsgroup();
    } else if (code == COM_LIST_ART) {
        listArticles();
    } else if (code == COM_CREATE_ART) {
        createArticle();
    } else {
        cout << code << " has no implemented function" << "\n";
    }
};

/*Methods*/
void ServerCommandHandler::listNewsgroups() {
    Protocol code = static_cast<Protocol>(msgh.recCode());
    std::vector<Newsgroup> list = dbptr->listNewsgroups();  
    if (code == COM_END) {
        msgh.sendCode(ANS_LIST_NG);
        cout << "Sending int: list.size() = " << list.size() << "\n";
        msgh.sendIntParameter(list.size());
        cout << "Starting send group names and ids..." << "\n";
        for (Newsgroup group : list) {
            cout << group.id << " : " << group.name << "\n";
            msgh.sendIntParameter(group.id);
            msgh.sendStringParameter(group.name);
        }
        cout << "Sending ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }
    /*cout << "Sending: ANS_LIST_NG" << "\n";
    msgh.sendCode(ANS_LIST_NG);
    std::vector<Newsgroup> list = dbptr->listNewsgroups();
    cout << "Sending int: list.size() = " << list.size() << "\n";
    msgh.sendInt(list.size());
    for (Newsgroup group : list) {
        msgh.sendStringParameter(group.name);
    }*/
};
void ServerCommandHandler::createNewsgroup(){
    //cout << "Sending: ANS_CREATE_NG" << "\n";
    //msgh.sendCode(ANS_CREATE_NG);
    string newsgroup_name = msgh.recStringParameter();
    Protocol code = static_cast<Protocol>(msgh.recCode());
    if (code == COM_END) {
        cout << "Received group name: " << newsgroup_name << "\n";
        msgh.sendCode(ANS_CREATE_NG);
        bool status = dbptr->createNewsgroup(newsgroup_name);
        if (status == true) {
            cout << "Created newsgroup: " << newsgroup_name << "\n";
            msgh.sendCode(ANS_ACK);
        } else {
            cout << "FAILED creating newsgroup " << newsgroup_name << "\n";
            msgh.sendCode(ANS_NAK);
        }
        msgh.sendCode(ANS_END);
    }
    /*cout << "Received group name: " << newsgroup_name << "\n";
    bool status = dbptr->createNewsgroup(newsgroup_name);
    if (status == true) {
        cout << "Created newsgroup: " << newsgroup_name << "\n";
        msgh.sendCode(ANS_ACK);
    } else {
        cout << "FAILED creating newsgroup " << newsgroup_name << "\n";
        msgh.sendCode(ANS_NAK);
    }*/
};

    /*TEMPORARY! The testserver selects newsgroups by id, but the delete function in MemoryDatabase
    uses groupnames*/
    std::string getNameById(MemoryDatabase& db, int targetId) {
        std::vector<Newsgroup> groups = db.listNewsgroups();
        for (const auto& group : groups) {
            if (group.id == targetId) {
                return group.name;
            }
        }
        return "NOT_FOUND";
    }

void ServerCommandHandler::deleteNewsgroup(){

    int groupIndex = msgh.recIntParameter();
    cout << "Received group index: " << groupIndex << "\n";
    Protocol code = static_cast<Protocol>(msgh.recCode());
    cout << "Received code: " << code << "\n";
    if (code == COM_END) {
        cout << "Sending : ANS_DELETE_NG" << "\n";
        msgh.sendCode(ANS_DELETE_NG);
        bool status = dbptr->deleteNewsgroup(getNameById(*dbptr,groupIndex));
        if (status != false) {
            cout << "Group deleted" << "\n";
            msgh.sendCode(ANS_ACK);
        } else {
            cout << "Failed deleting group" << "\n";
            msgh.sendCode(ANS_NAK);
        }
        cout << "Sending : ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }

    /*
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
    }*/
};
void ServerCommandHandler::listArticles(){
    int groupId = msgh.recIntParameter();
    cout << "Received groupId: " << groupId << "\n";
    Protocol code = static_cast<Protocol>(msgh.recCode());
    cout << "Received code: " << code << "\n";
    if (code == COM_END) {
        cout << "Sending code: ANS_LIST_ART" << "\n";
        msgh.sendCode(ANS_LIST_ART);
        std::vector<Article> articles = dbptr->listArticles(getNameById(*dbptr,groupId));
        if (articles.size() == 0) {
            cout << "No articles in newsgroup" << "\n";
            cout << "Sending code: ANS_NAK" << "\n";
            msgh.sendCode(ANS_NAK);
            cout << "Sending code: ERR_ART_DOES_NOT_EXIST" << "\n";
            msgh.sendCode(ERR_ART_DOES_NOT_EXIST);
            cout << "Sending code: ANS_NAK" << "\n";
            msgh.sendCode(ANS_NAK);
            return;
        }
        cout << "Sending code: ANS_ACK" << "\n";
        msgh.sendCode(ANS_ACK);
        cout << "Sending article list size: " << articles.size() <<"\n";
        msgh.sendIntParameter(articles.size());
        cout << "Starting send article names and ids..." << "\n";
        for (Article article : articles) {
            cout << article.id << " : " << article.title << "\n";
            msgh.sendIntParameter(article.id);
            msgh.sendStringParameter(article.title);
        }
        cout << "Sending code: ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }
};
void ServerCommandHandler::createArticle(){
    int groupId = msgh.recIntParameter();
    cout << "Received groupId: " << groupId << "\n";
    string title = msgh.recStringParameter();
    cout << "Received title: " << title << "\n";
    string author = msgh.recStringParameter();
    cout << "Received author: " << author << "\n";
    string text = msgh.recStringParameter();
    cout << "Received text: " << text << "\n";
    Protocol code = static_cast<Protocol>(msgh.recCode());
    bool status;
    if (code == COM_END) {
        cout << "Sending code: ANS_CREATE_ART" << "\n";
        msgh.sendCode(ANS_CREATE_ART);
        status = dbptr->createArticle(getNameById(*dbptr,groupId),title,author,text);
        if (status == true) {
            cout << "Article created" << "\n";
            cout << "Sending code: ANS_ACK" << "\n";
            msgh.sendCode(ANS_ACK);
        } else {
            cout << "FAILED creating article" << "\n";
            cout << "Sending code: ANS_NAK" << "\n";
            msgh.sendCode(ANS_NAK);
            cout << "Sending code: UNDEFINED" << "\n";
            msgh.sendCode(UNDEFINED);
        }
        cout << "Sending code: ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }
};
void ServerCommandHandler::deleteArticle(){};
void ServerCommandHandler::getArticle(){};