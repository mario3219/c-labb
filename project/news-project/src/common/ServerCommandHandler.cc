#include "ServerCommandHandler.h"
#include "MessageHandler.h"
#include <list>
#include <string>
#include <iostream>
#include "protocol.h"
#include "MemoryDatabase.h"
#include "IDatabase.h"
#include <algorithm>
#include <vector>

using std::cout;
using std::list;
using std::string;
using enum Protocol;

ServerCommandHandler::ServerCommandHandler(const std::shared_ptr<Connection> &conn, IDatabase *dbptr) : msgh(*conn), dbptr(dbptr)
{
}

/*Checks commandbyte, then executes appropriate method
according to what command is returned*/
void ServerCommandHandler::process()
{
    cout << "---Waiting for new request---" << "\n";
    Protocol code = static_cast<Protocol>(msgh.recCode());
    cout << "Received code: " << code << "\n";
    switch (code){
        case COM_LIST_NG: {
        listNewsgroups();
        break;
    }
        case COM_CREATE_NG: {
        createNewsgroup();
        break;
    }
        case COM_DELETE_NG: {
        deleteNewsgroup();
        break;
    }
        case COM_LIST_ART: {
        listArticles();
        break;
    }
        case COM_CREATE_ART: {
        createArticle();
        break;
    }
        case COM_DELETE_ART: {
        deleteArticle();
        break;
    }
        case COM_GET_ART: {
        getArticle();
        break;
    }
        default:
        cout << code << " has no implemented function" << "\n";
        break;
    }
};

/*Methods*/

void ServerCommandHandler::listNewsgroups()
{
    Protocol code = static_cast<Protocol>(msgh.recCode());
    std::vector<Newsgroup> list = dbptr->listNewsgroups();
    if (code == COM_END)
    {
        msgh.sendCode(ANS_LIST_NG);
        cout << "Sending int: list.size() = " << list.size() << "\n";
        msgh.sendIntParameter(list.size());
        cout << "Starting send group names and ids..." << "\n";
        for (Newsgroup group : list)
        {
            cout << group.id << " : " << group.name << "\n";
            msgh.sendIntParameter(group.id);
            msgh.sendStringParameter(group.name);
        }
        cout << "Sending ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }
};

void ServerCommandHandler::createNewsgroup()
{
    string newsgroup_name = msgh.recStringParameter();
    Protocol code = static_cast<Protocol>(msgh.recCode());
    if (code == COM_END)
    {
        cout << "Received group name: " << newsgroup_name << "\n";
        msgh.sendCode(ANS_CREATE_NG);
        bool status = dbptr->createNewsgroup(newsgroup_name);
        if (status == true)
        {
            cout << "Created newsgroup: " << newsgroup_name << "\n";
            cout << "Sending code: ANS_ACK" << "\n";
            msgh.sendCode(ANS_ACK);
        }
        else
        {
            cout << "FAILED creating newsgroup " << newsgroup_name << "\n";
            cout << "Sending code: ANS_NAK" << "\n";
            msgh.sendCode(ANS_NAK);
            cout << "Sending code: ERR_NG_ALREADY_EXISTS" << "\n";
            msgh.sendCode(ERR_NG_ALREADY_EXISTS);
        }
        cout << "Sending code: ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }
};

void ServerCommandHandler::deleteNewsgroup()
{

    int groupIndex = msgh.recIntParameter();
    cout << "Received group index: " << groupIndex << "\n";
    Protocol code = static_cast<Protocol>(msgh.recCode());
    cout << "Received code: " << code << "\n";
    if (code == COM_END)
    {
        cout << "Sending : ANS_DELETE_NG" << "\n";
        msgh.sendCode(ANS_DELETE_NG);
        bool status = dbptr->deleteNewsgroup(groupIndex);
        if (status != false)
        {
            cout << "Group deleted" << "\n";
            msgh.sendCode(ANS_ACK);
        }
        else
        {
            cout << "Failed deleting group" << "\n";
            cout << "Sending code: ANS_NAK" << "\n";
            msgh.sendCode(ANS_NAK);
            cout << "Sending code: ERR_NG_DOES_NOT_EXIST" << "\n";
            msgh.sendCode(ERR_NG_DOES_NOT_EXIST);
        }
        cout << "Sending : ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }
};

void ServerCommandHandler::listArticles()
{
    int groupId = msgh.recIntParameter();
    cout << "Received groupId: " << groupId << "\n";
    Protocol code = static_cast<Protocol>(msgh.recCode());
    cout << "Received code: " << code << "\n";
    if (code == COM_END)
    {
        cout << "Sending code: ANS_LIST_ART" << "\n";
        msgh.sendCode(ANS_LIST_ART);
        std::vector<Newsgroup> list = dbptr->listNewsgroups();

        auto it = std::find_if(list.begin(), list.end(), [groupId](const Newsgroup &s)
                               { return s.id == groupId; });
        if (it == list.end())
        {
            cout << "Sending code: ANS_NAK" << "\n";
            msgh.sendCode(ANS_NAK);
            cout << "Sending code: ERR_NG_DOES_NOT_EXIST" << "\n";
            msgh.sendCode(ERR_NG_DOES_NOT_EXIST);
            cout << "Sending code: ANS_NAK" << "\n";
            msgh.sendCode(ANS_NAK);
            return;
        }

        std::vector<Article> articles = dbptr->listArticles(groupId);
        std::sort(articles.begin(), articles.end(), [](const Article &a, const Article &b)
                  { return a.id < b.id; });
        cout << "Sending code: ANS_ACK" << "\n";
        msgh.sendCode(ANS_ACK);
        cout << "Sending article list size: " << articles.size() << "\n";
        msgh.sendIntParameter(articles.size());
        cout << "Starting send article names and ids..." << "\n";
        for (Article article : articles)
        {
            cout << article.id << " : " << article.title << "\n";
            msgh.sendIntParameter(article.id);
            msgh.sendStringParameter(article.title);
        }
        cout << "Sending code: ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }
};
void ServerCommandHandler::createArticle()
{
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
    if (code == COM_END)
    {
        cout << "Sending code: ANS_CREATE_ART" << "\n";
        msgh.sendCode(ANS_CREATE_ART);
        status = dbptr->createArticle(groupId, title, author, text);
        if (status == true)
        {
            cout << "Article created" << "\n";
            cout << "Sending code: ANS_ACK" << "\n";
            msgh.sendCode(ANS_ACK);
        }
        else
        {
            cout << "FAILED creating article" << "\n";
            cout << "Sending code: ANS_NAK" << "\n";
            msgh.sendCode(ANS_NAK);
            cout << "Sending code: ERR_NG_DOES_NOT_EXIST" << "\n";
            msgh.sendCode(ERR_NG_DOES_NOT_EXIST);
        }
        cout << "Sending code: ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }
};
void ServerCommandHandler::deleteArticle()
{
    int groupId = msgh.recIntParameter();
    cout << "Received groupId: " << groupId << "\n";
    int articleId = msgh.recIntParameter();
    cout << "Received articleId: " << articleId << "\n";
    Protocol code = static_cast<Protocol>(msgh.recCode());
    cout << "Received code: " << code << "\n";
    if (code == COM_END)
    {
        cout << "Sending code: ANS_DELETE_ART" << "\n";
        msgh.sendCode(ANS_DELETE_ART);
        bool status = dbptr->deleteArticle(groupId, articleId);
        if (status == true)
        {
            cout << "Sending code: ANS_ACK" << "\n";
            msgh.sendCode(ANS_ACK);
            cout << "Article deleted" << "\n";
        }
        else
        {
            cout << "Sending code: ANS_NAK" << "\n";
            msgh.sendCode(ANS_NAK);
            cout << "Sending code: ERR_ART_DOES_NOT_EXIST" << "\n";
            msgh.sendCode(ERR_ART_DOES_NOT_EXIST);
        }
        cout << "Sending code: ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }
};
void ServerCommandHandler::getArticle()
{
    int groupId = msgh.recIntParameter();
    cout << "Received groupId: " << groupId << "\n";
    int articleId = msgh.recIntParameter();
    cout << "Received articleId" << articleId << "\n";
    Protocol code = static_cast<Protocol>(msgh.recCode());
    cout << "Received code: " << code << "\n";
    if (code == COM_END)
    {
        cout << "Sending code: ANS_GET_ART" << "\n";
        msgh.sendCode(ANS_GET_ART);
        Article article;
        try
        {
            article = dbptr->getArticle(groupId, articleId);
        }
        catch (const std::runtime_error& e)
        {
            cout << e.what() << "\n";
            cout << "Sending code: ANS_NAK" << "\n";
            msgh.sendCode(ANS_NAK);
            cout << "Sending code: ERR_ART_DOES_NOT_EXIST" << "\n";
            msgh.sendCode(ERR_ART_DOES_NOT_EXIST);
            cout << "Sending code: ANS_END" << "\n";
            msgh.sendCode(ANS_END);
            return;
        }
        cout << "Sending code: ANS_ACK" << "\n";
        msgh.sendCode(ANS_ACK);
        cout << "Sending title: " << article.title << "\n";
        msgh.sendStringParameter(article.title);
        cout << "Sending author: " << article.author << "\n";
        msgh.sendStringParameter(article.author);
        cout << "Sending text: " << article.content << "\n";
        msgh.sendStringParameter(article.content);
        cout << "Sending code: ANS_END" << "\n";
        msgh.sendCode(ANS_END);
    }
};
