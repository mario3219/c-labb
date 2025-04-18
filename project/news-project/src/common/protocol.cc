#include "protocol.h"

/*This class is purely to provide a server output for debugging*/

std::ostream& operator<<(std::ostream& os, Protocol p) {
    return os << to_string(p);
}