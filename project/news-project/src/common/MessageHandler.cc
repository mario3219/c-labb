#include "MessageHandler.h"

/*Constructors and destructors*/
MessageHandler::MessageHandler(const Connection& conn) : conn(conn) {}

/*Sending methods*/
void MessageHandler::sendCode(int code) {};
void MessageHandler::sendInt(int value) {};
void MessageHandler::sendString(string str) {};
void MessageHandler::sendStringParameter(string param) {};
void MessageHandler::sendIntParameter(int param) {};

/*Receiving methods*/
int MessageHandler::recCode() {return 0;};
int MessageHandler::recInt() {return 0;};
string MessageHandler::recString() {return ""};
string MessageHandler::recStringParameter() {return ""};
int MessageHandler::recIntParameter() {return 0};

/*Private methods*/
void MessageHandler::sendByte(int code) {};
void MessageHandler::recByte() {};