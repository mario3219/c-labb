# include <iostream>
# include "coding.h"

int main() {
    std::string s;
    while(std::cin >> s){
        std::string encoded_s;
        for (auto& c : s) {
            encoded_s += decode(c);
        }
        std::cout << encoded_s << " ";
    }
}
