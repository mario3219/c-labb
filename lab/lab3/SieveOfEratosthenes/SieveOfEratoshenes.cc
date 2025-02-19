#include "SieveOfEratoshenes.h"
#include <string>
#include <iostream>

using namespace std;

SieveOfEratoshenes::SieveOfEratoshenes(int n) : s("") {
    s = "";
    for (int i = 0; i < n; i++){
        s += to_string(i);
    }
}

void SieveOfEratoshenes::print(){
    cout << s;
}
