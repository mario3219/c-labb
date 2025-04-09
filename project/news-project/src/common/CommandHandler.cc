#include "CommandHandler.h"
#include <list>
#include <string>
#include "protocol.h"

using std::string;
using std::list;
using enum Protocol;

/*Constructors and destructors*/
CommandHandler::CommandHandler(const Connection& conn) {
    MessageHandler msgh(conn);
}

/*Checks commandbyte, then executes appropriate method
according to what command is returned*/
void process();

/*Methods*/
void listNewsgroups();
void createNewsgroup();
void deleteNewsgroup();
void listArticles();
void createArticle();
void deleteArticle();
void getArticle();