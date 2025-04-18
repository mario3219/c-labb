#ifndef SERVERCOMMANDHANDLER_H
#define SERVERCOMMANDHANDLER_H

#include "MessageHandler.h"
#include "MemoryDatabase.h"
#include <list>
#include <string>

using std::list;
using std::string;

class ServerCommandHandler
{
public:
    /*Constructors and destructors*/
    ServerCommandHandler(const std::shared_ptr<Connection>& conn, MemoryDatabase* dbptr);
    ~ServerCommandHandler() = default;

    /*Checks commandbyte, then executes appropriate method
    according to what command is returned*/
    void process();

private:
    MessageHandler msgh;
    MemoryDatabase* dbptr;

    /*Methods*/
    void listNewsgroups();
    void createNewsgroup();
    void deleteNewsgroup();
    void listArticles();
    void createArticle();
    void deleteArticle();
    void getArticle();
};

#endif