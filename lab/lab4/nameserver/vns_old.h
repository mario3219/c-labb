// wrong implementation, didn't implement the interface...

#ifndef VNS_H
#define VNS_H

#include <vector>

using namespace std;

// create data structure for pairs
struct pairs{
    pairs(string name, int address):name(name),address(address) {}
    string name;
    int address;
};

class VNS {
    public:
        // constructors
        VNS()=default;

        VNS(pairs pair) {
            pairs_vector.push_back(pair);};
        
        VNS(string& name, int& address) {
            pairs_vector.push_back(pairs(name,address));
        };

        // default destructor
        ~ VNS()=default;

        // functions
        string find(int& address) {
            return "none";
        };

    private:
        vector<pairs> pairs_vector;
};

#endif