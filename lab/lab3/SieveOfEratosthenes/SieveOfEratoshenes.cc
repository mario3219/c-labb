#include "SieveOfEratoshenes.h"
#include <string>
#include <iostream>

using namespace std;

string s;

SieveOfEratoshenes::SieveOfEratoshenes(int n){
    s = "";
    for (int i = 0; i < n; i++){
        s += to_string(i);
    }
}

void SieveOfEratoshenes::printString(){
    cout << s;
}
