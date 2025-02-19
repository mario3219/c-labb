#ifndef SieveOfEratoshenes_H
#define SieveOfEratoshenes_H

#include <string>
#include <vector>

using namespace std;

class SieveOfEratoshenes {
    public:
        SieveOfEratoshenes(int n);
        void print();
        string process();
        vector<int> primes();
    private:
        string s;
    };

#endif