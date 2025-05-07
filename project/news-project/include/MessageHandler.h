#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "connection.h"
#include "protocol.h"
#include <string>
#include <memory>
using std::string;

class MessageHandler {
    public:
        /*Constructors and destructors*/
        MessageHandler(const Connection& con);
        ~MessageHandler() = default;

        /*Sending methods*/
        void sendCode(Protocol code);
        void sendInt(int value);                    
        void sendStringParameter(string param);
        void sendIntParameter(int param);
        
        /*Receiving methods*/
        int recCode();
        int recInt();
        string recStringParameter();
        int recIntParameter();

    //private:
        void sendByte(int code);
        int recByte();
        const Connection& conn;
};

#endif