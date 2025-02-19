#include "SieveOfEratoshenes.h"
#include <iostream>
#include <vector>

int main()
{
    SieveOfEratoshenes soe(200);
    soe.process();
    soe.print();
    for (auto i : soe.primes()){
        cout << i << " ";
    }
    SieveOfEratoshenes soe2(100000);
    soe2.process();
    cout << soe2.primes().back() << "\n";
    return 0;
}
