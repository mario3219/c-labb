#include "ClientCommandHandler.h"
#include "MessageHandler.h"
#include <list>
#include <string>
#include "protocol.h"
#include <string>
#include <iostream>
#include <limits>

using std::cin;
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
        createNewsgroup(name);
    }
    else if (input == "3") {
	cout << "Input newsgroup id: ";
        int groupId;
	cin >> groupId;
        deleteNewsgroup(groupId);
    }
    else if (input == "4") {
	int groupId;
	cout << "Input newsgroup id: ";
	cin >> groupId;
	listArticles(groupId);
    }
    else if (input == "5") {
	int groupId;
	string title;
	string author;
	string text;
	cout << "Input newsgroup id: ";
	cin >> groupId;
	cout << "Input article title: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, title);
	cout << "Input author: ";
        std::getline(std::cin, author);
	cout << "Input text: ";
        std::getline(std::cin, text);
	createArticle(groupId, title, author, text);
    }
    else if (input == "6") {
	int groupId;
	int articleId;
	cout << "Input newsgroup id: ";
	cin >> groupId;
	cout << "Input article id: ";
	cin >> articleId;
	deleteArticle(groupId, articleId);
    }
    else if (input == "7") {
	int groupId;
	int articleId;
	cout << "Input newsgroup id: ";
	cin >> groupId;
	cout << "Input article id: ";
	cin >> articleId;
	getArticle(groupId, articleId);
    }
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
	    }
    }msgh.recCode();
};
void ClientCommandHandler::deleteNewsgroup(int groupId) {
	msgh.sendCode(COM_DELETE_NG);
    	msgh.sendIntParameter(groupId);
   	msgh.sendCode(COM_END);
    	msgh.recCode();
 	Protocol code = static_cast<Protocol>(msgh.recCode());
	if (code != ANS_NAK) {
		cout << "Newsgroup deleted" << "\n";
	} else {
		cout << "Newsgroup not found" << "\n";
		msgh.recCode();
	} msgh.recCode();
};
void ClientCommandHandler::listArticles(int groupId) {
	msgh.sendCode(COM_LIST_ART);
	msgh.sendIntParameter(groupId);
	msgh.sendCode(COM_END);
	Protocol code = static_cast<Protocol>(msgh.recCode());
	if (code == ANS_LIST_ART) {	
		code = static_cast<Protocol>(msgh.recCode());
		if (code != ANS_NAK) {
			int list_size = msgh.recIntParameter();
			for (int i = 0; i < list_size; i++) {
				int articleId = msgh.recIntParameter();
				string articleName = msgh.recStringParameter();
				cout << articleId << " : " << articleName << "\n";
			}
			code = static_cast<Protocol>(msgh.recCode());
		} else {
			code = static_cast<Protocol>(msgh.recCode());
			cout << code << "\n";
			code = static_cast<Protocol>(msgh.recCode());
		}
	}
};
void ClientCommandHandler::createArticle(int groupId, string title, string author, string text) {
	msgh.sendCode(COM_CREATE_ART);
	msgh.sendIntParameter(groupId);
	msgh.sendStringParameter(title);
	msgh.sendStringParameter(author);
	msgh.sendStringParameter(text);
	msgh.sendCode(COM_END);
	Protocol code = static_cast<Protocol>(msgh.recCode());
	if (code == ANS_CREATE_ART) {
		code = static_cast<Protocol>(msgh.recCode());
		if (code != ANS_NAK) {
			cout << "Article created" << "\n";
		} else {
			code = static_cast<Protocol>(msgh.recCode());
			cout << code << "\n";
		} msgh.recCode();
	}
};
void ClientCommandHandler::deleteArticle(int groupId, int articleId) {
	msgh.sendCode(COM_DELETE_ART);
	msgh.sendIntParameter(groupId);
	msgh.sendIntParameter(articleId);
	msgh.sendCode(COM_END);
	msgh.recCode();
	Protocol code = static_cast<Protocol>(msgh.recCode());
	if (code == ANS_NAK) {
		code = static_cast<Protocol>(msgh.recCode());
		cout << code << "\n";
	} else {
		cout << "Article deleted" << "\n";
	} msgh.recCode();
};
void ClientCommandHandler::getArticle(int groupId, int articleId) {
	msgh.sendCode(COM_GET_ART);
	msgh.sendIntParameter(groupId);
	msgh.sendIntParameter(articleId);
	msgh.sendCode(COM_END);
	Protocol code = static_cast<Protocol>(msgh.recCode());
	if (code == ANS_GET_ART) {
		code = static_cast<Protocol>(msgh.recCode());
		if (code != ANS_NAK) {
			string title = msgh.recStringParameter();
			string author = msgh.recStringParameter();
			string text = msgh.recStringParameter();
			cout << "Title: " << title << "\n";
			cout << "Author: " << author << "\n";
			cout << "---------------" << "\n";
			cout << text << "\n";
		} else {
			cout << "Article not found" << "\n";
		}
	} msgh.recCode();
};
