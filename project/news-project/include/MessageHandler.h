#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "connection.h"
#include <string>

using std::string;

class MessageHandler {
    public:
        /*Constructors and destructors*/
        MessageHandler(const Connection& conn);
        ~MessageHandler() = default;

        /*Sending methods*/
        void sendCode(int code);
        void sendInt(int value);                    
        void sendString(string str);
        void sendStringParameter(string param);
        void sendIntParameter(int param);
        
        /*Receiving methods*/
        int recCode();
        int recInt();
        string recString();
        string recStringParameter();
        int recIntParameter();

    private:
        void sendByte(int code);
        void recByte();

        Connection& conn;
};

#endif