#include "MessageHandler.h"
#include <memory>
#include <stdexcept>

using std::string;
/*Constructors and destructors*/
// MessageHandler::MessageHandler(const std::shared_ptr<Connection>& con) : conn(con) {}
MessageHandler::MessageHandler(const Connection &con) : conn(con) {}

/*Private methods*/
void MessageHandler::sendByte(int code)
{
    // conn->write(static_cast<char>(code));
    conn.write(static_cast<char>(code));
}
int MessageHandler::recByte()
{
    // int code = static_cast<int>(conn->read());
    int code = static_cast<int>(conn.read());
    return code;
}

/*Sending methods*/

void MessageHandler::sendCode(Protocol code)
{
    sendByte(static_cast<int>(code));
}

void MessageHandler::sendInt(int value)
{
    sendByte((value >> 24) & 0xFF);

    sendByte((value >> 16) & 0xFF);

    sendByte((value >> 8) & 0xFF);

    sendByte(value & 0xFF);
}

// void MessageHandler::sendString(string str) {};

void MessageHandler::sendStringParameter(string param)
{
    sendCode(Protocol::PAR_STRING);
    sendInt(static_cast<int>(param.length()));
    for (size_t i = 0; i < param.length(); i++)
    {
        sendByte(param[i]);
    }
};

void MessageHandler::sendIntParameter(int param)
{
    sendCode(Protocol::PAR_NUM);
    sendInt(param);
}

/*Receiving methods*/
int MessageHandler::recCode()
{
    int code = recByte();
    return code;
}

int MessageHandler::recInt()
{
    int b1 = recByte();

    int b2 = recByte();

    int b3 = recByte();

    int b4 = recByte();

    return b1 << 24 | b2 << 16 | b3 << 8 | b4;
}

// string MessageHandler::recString() {return ""};

string MessageHandler::recStringParameter()
{
    int code = recCode(); // Doesnt check if the code is PAR_STRING! FIX
    if (code != static_cast<int>(Protocol::PAR_STRING))
    {
        throw std::runtime_error("Expected PAR_STRING code");
    }
    int n = recInt();
    //if (n<0)
    //{
    //    throw std::runtime_error("Number of characters < 0");
    //}

    string result;

    for (int i = 0; i < n; i++)
    {
        // char ch = static_cast<char>(conn->read());
        char ch = static_cast<char>(conn.read());
        result += ch;
    }
    return result;
}

int MessageHandler::recIntParameter()
{
    int code = recCode();
    if (code != static_cast<int>(Protocol::PAR_NUM))
    {
        throw std::runtime_error("Expected PAR_NUM code");
    }
    return recInt();
}
