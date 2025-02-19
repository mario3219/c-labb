#include "SieveOfEratoshenes.h"
#include <string>
#include <iostream>

using namespace std;

SieveOfEratoshenes::SieveOfEratoshenes(int n) : s("") {
    s.append(n, 'C');
}

void SieveOfEratoshenes::print(){
    cout << s;
}
