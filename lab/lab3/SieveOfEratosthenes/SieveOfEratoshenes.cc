#include "SieveOfEratoshenes.h"
#include <string>
#include <iostream>

using namespace std;

SieveOfEratoshenes::SieveOfEratoshenes(int n) {
    s.append(2, 'C');
    s.append(n-2, 'P');

}

void SieveOfEratoshenes::print(){
    cout << s + "\n";
}

string SieveOfEratoshenes::process(){
    for (int i = 2; i < s.length(); i++) {
        if (s[i] == 'P') {
            for (int j = i*2; j < s.length(); j+=i){
                s[j] = 'C';
                print();
            }
        }
    }
    return s;
}