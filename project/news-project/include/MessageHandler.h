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
        //MessageHandler(const std::shared_ptr<Connection>& con);
        MessageHandler(const Connection& con);
        ~MessageHandler() = default;

        /*Sending methods*/
        void sendCode(Protocol code);
        void sendInt(int value);                    
        //void sendString(string str);
        void sendStringParameter(string param);
        void sendIntParameter(int param);
        
        /*Receiving methods*/
        int recCode();
        int recInt();
        //string recString();
        string recStringParameter();
        int recIntParameter();

    //private:
        void sendByte(int code);
        int recByte();
        //std::shared_ptr<Connection> conn;
        const Connection& conn;
};

#endif