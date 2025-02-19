#include "SieveOfEratoshenes.h"
#include <string>
#include <iostream>

using namespace std;

SieveOfEratoshenes::SieveOfEratoshenes(int n) : s("") {
    s.append(2, 'C');
    s.append(n-2, 'P');
}

void SieveOfEratoshenes::print(){
    cout << s;
}

string SieveOfEratoshenes::process(){
    
    for (int i = 2; i < s.length(); i++) {
        if (s[i] == 'C') {
            for (int j = i; i < s.length(); j+i){
                s[j] = 'P';
            }
        }
    }
    return s;
}