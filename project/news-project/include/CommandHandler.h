#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "MessageHandler.h"
#include <list>
#include <string>

using std::string;
using std::list;

class CommandHandler {
    public:
        /*Constructors and destructors*/
        CommandHandler(const Connection& conn);
        ~CommandHandler() = default;

        /*Methods, client -> server*/
        void sendNewsgroups();
        list<string> recNewsgroups();

        /*Methods, server -> client*/

        /*General methods*/
        void createNewsgroup();
        void deleteNewsgroup();
        list<string> listArticles();
        void deleteArticle();
        string getArticle();

    private:
        MessageHandler msgh;
};

#endif