#include "CommandHandler.h"
#include <list>

CommandHandler::CommandHandler(const Connection& conn) {
    MessageHandler msgh(conn);
}