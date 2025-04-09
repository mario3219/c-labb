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

        /*Checks commandbyte, then executes appropriate method
        according to what command is returned*/
        void process();

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