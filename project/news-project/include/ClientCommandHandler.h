#ifndef CLIENTCOMMANDHANDLER_H
#define CLIENTCOMMANDHANDLER_H

#include "MessageHandler.h"
#include <list>
#include <string>

using std::list;
using std::string;

class ClientCommandHandler
{
public:
    /*Constructors and destructors*/
    ClientCommandHandler(const Connection &conn);
    ~ClientCommandHandler() = default;

    /*Checks commandbyte, then executes appropriate method
    according to what command is returned*/
    void process(string input);

private:
    MessageHandler msgh;

    /*Methods*/
    void listNewsgroups();
    void createNewsgroup(string newsgroup_name);
    void deleteNewsgroup(string newsgroup_name);
    void listArticles();
    void createArticle();
    void deleteArticle();
    void getArticle();
};

#endif