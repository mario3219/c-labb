#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "MessageHandler.h"
#include <list>
#include <string>

using std::list;
using std::string;

class ServerCommandHandler
{
public:
    /*Constructors and destructors*/
    ServerCommandHandler(const Connection &conn);
    ~ServerCommandHandler() = default;

    /*Checks commandbyte, then executes appropriate method
    according to what command is returned*/
    void process(string input);

private:
    MessageHandler msgh;

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