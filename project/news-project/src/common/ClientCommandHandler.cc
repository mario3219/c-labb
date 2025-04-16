#include "ClientCommandHandler.h"
#include "MessageHandler.h"
#include <list>
#include <string>
#include "protocol.h"

using std::list;
using std::string;
using enum Protocol;

/*Constructors and destructors*/
ClientCommandHandler::ClientCommandHandler(const Connection &conn) : msgh(conn) {}

/*Checks commandbyte, then executes appropriate method
according to what command is returned*/
void process(string input);

/*Methods*/
void listNewsgroups();
void createNewsgroup();
void deleteNewsgroup();
void listArticles();
void createArticle();
void deleteArticle();
void getArticle();