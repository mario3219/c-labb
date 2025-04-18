/*
 * Protocol: definitions of command and error codes
 * for the messaging protocol used in the news system project,
 * C++ Programming course.
 */

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>

enum class Protocol {
        UNDEFINED = 0, // not used in protocol

        /* Command codes, client -> server */
        COM_LIST_NG    = 1, // list newsgroups
        COM_CREATE_NG  = 2, // create newsgroup
        COM_DELETE_NG  = 3, // delete newsgroup
        COM_LIST_ART   = 4, // list articles
        COM_CREATE_ART = 5, // create article
        COM_DELETE_ART = 6, // delete article
        COM_GET_ART    = 7, // get article
        COM_END        = 8, // command end

        /* Answer codes, server -> client */
        ANS_LIST_NG    = 20, // answer list newsgroups
        ANS_CREATE_NG  = 21, // answer create newsgroup
        ANS_DELETE_NG  = 22, // answer delete newsgroup
        ANS_LIST_ART   = 23, // answer list articles
        ANS_CREATE_ART = 24, // answer create article
        ANS_DELETE_ART = 25, // answer delete article
        ANS_GET_ART    = 26, // answer get article
        ANS_END        = 27, // answer end
        ANS_ACK        = 28, // acknowledge
        ANS_NAK        = 29, // negative acknowledge

        /* Parameters */
        PAR_STRING = 40, // string
        PAR_NUM    = 41, // number

        /* Error codes */
        ERR_NG_ALREADY_EXISTS  = 50, // newsgroup already exists
        ERR_NG_DOES_NOT_EXIST  = 51, // newsgroup does not exist
        ERR_ART_DOES_NOT_EXIST = 52  // article does not exist
};

/*The following methods are purely to provide a server output for debugging*/


inline std::string to_string(Protocol code) {
        switch (code) {
            case Protocol::UNDEFINED: return "UNDEFINED";
    
            case Protocol::COM_LIST_NG: return "COM_LIST_NG";
            case Protocol::COM_CREATE_NG: return "COM_CREATE_NG";
            case Protocol::COM_DELETE_NG: return "COM_DELETE_NG";
            case Protocol::COM_LIST_ART: return "COM_LIST_ART";
            case Protocol::COM_CREATE_ART: return "COM_CREATE_ART";
            case Protocol::COM_DELETE_ART: return "COM_DELETE_ART";
            case Protocol::COM_GET_ART: return "COM_GET_ART";
            case Protocol::COM_END: return "COM_END";
    
            case Protocol::ANS_LIST_NG: return "ANS_LIST_NG";
            case Protocol::ANS_CREATE_NG: return "ANS_CREATE_NG";
            case Protocol::ANS_DELETE_NG: return "ANS_DELETE_NG";
            case Protocol::ANS_LIST_ART: return "ANS_LIST_ART";
            case Protocol::ANS_CREATE_ART: return "ANS_CREATE_ART";
            case Protocol::ANS_DELETE_ART: return "ANS_DELETE_ART";
            case Protocol::ANS_GET_ART: return "ANS_GET_ART";
            case Protocol::ANS_END: return "ANS_END";
            case Protocol::ANS_ACK: return "ANS_ACK";
            case Protocol::ANS_NAK: return "ANS_NAK";
    
            case Protocol::PAR_STRING: return "PAR_STRING";
            case Protocol::PAR_NUM: return "PAR_NUM";
    
            case Protocol::ERR_NG_ALREADY_EXISTS: return "ERR_NG_ALREADY_EXISTS";
            case Protocol::ERR_NG_DOES_NOT_EXIST: return "ERR_NG_DOES_NOT_EXIST";
            case Protocol::ERR_ART_DOES_NOT_EXIST: return "ERR_ART_DOES_NOT_EXIST";
    
            default: return "UNKNOWN";
        }
    }

    std::ostream& operator<<(std::ostream& os, Protocol p);
    

#endif
