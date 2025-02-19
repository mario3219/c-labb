#ifndef SieveOfEratoshenes_H
#define SieveOfEratoshenes_H

#include <string>

using namespace std;

class SieveOfEratoshenes {
    public:
        SieveOfEratoshenes(int n);
        void print();
        string process();
    private:
        string s;
    };

#endif