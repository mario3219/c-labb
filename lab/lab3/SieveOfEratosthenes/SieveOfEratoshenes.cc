#include "SieveOfEratoshenes.h"
#include <string>
#include <iostream>
#include <vector>

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
                //print();
            }
        }
    }
    return s;
}

vector<int> SieveOfEratoshenes::primes() {
    size_t i = 0;
    vector<int> primes;

    while (i != string::npos){
        i = s.find("P", i);
        if (i != string::npos){
            primes.push_back(static_cast<int>(i));
            i++;
        }
    }
    return primes;
}