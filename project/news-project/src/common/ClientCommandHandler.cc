#include "ClientCommandHandler.h"
#include "MessageHandler.h"
#include <list>
#include <string>
#include "protocol.h"
#include <string>
#include <iostream>
#include <limits>

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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, name);
        cout << "\n";
        createNewsgroup(name);
    }
    else if (input == "3") {
        cout << "Input newsgroup to delete: ";
        string name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, name);
        cout << "\n";
        deleteNewsgroup(name);
    }
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
    msgh.sendCode(COM_END);
    Protocol code = static_cast<Protocol>(msgh.recCode());
    if (code == ANS_LIST_NG) {
        int list_size = msgh.recIntParameter();
	for (int i = 0; i < list_size; i++) {
		cout << msgh.recIntParameter() << " : ";
		cout << msgh.recStringParameter() << "\n";
	}
    }
    code = static_cast<Protocol>(msgh.recCode());
};
void ClientCommandHandler::createNewsgroup(string newsgroup_name) {
    msgh.sendCode(COM_CREATE_NG);
    msgh.sendStringParameter(newsgroup_name);
    msgh.sendCode(COM_END);
    Protocol code = static_cast<Protocol>(msgh.recCode());
    if (code == ANS_CREATE_NG) {
	    code = static_cast<Protocol>(msgh.recCode());
	    if (code == ANS_ACK) {
		cout << "Newsgroup " << newsgroup_name << " created." << "\n";
	    } else if (code == ANS_NAK) {
		cout << "Failed to create newsgroup " << newsgroup_name << "\n";
		code = static_cast<Protocol>(msgh.recCode());
		cout << code << "\n";
	    }
    }msgh.recCode();
};
void ClientCommandHandler::deleteNewsgroup(string newsgroup_name) {
    msgh.sendCode(COM_DELETE_NG);
    Protocol code = static_cast<Protocol>(msgh.recCode());
    if (code == ANS_DELETE_NG) {
        msgh.sendStringParameter(newsgroup_name);
    }
    code = static_cast<Protocol>(msgh.recCode());
    if (code == ANS_ACK) {
        cout << "Newsgroup deleted" << "\n";
    } else if (code == ERR_NG_DOES_NOT_EXIST) {
        cout << "FAILED: Newsgroup does not exist" << "\n";
    } else {
        cout << "CODE ERROR: UNKNOWN MESSAGE" << "\n";
    }
};
void ClientCommandHandler::listArticles() {};
void ClientCommandHandler::createArticle() {};
void ClientCommandHandler::deleteArticle() {};
void ClientCommandHandler::getArticle() {};
