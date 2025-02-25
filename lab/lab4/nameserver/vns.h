#ifndef VNS_H
#define VNS_H

#include "nameserverinterface.h"
#include <vector>

using namespace std;

// create data structure for pairs
struct pairs{
    pairs(HostName name, IPAddress address):name(name),address(address) {}
    HostName name;
    IPAddress address;
};

class VNS : public NameServerInterface {
    public:
        // constructors
        VNS()=default;

        VNS(pairs pair) {
            pairs_vector.push_back(pair);};
        
        VNS(HostName name, IPAddress address) {
            pairs_vector.push_back(pairs(name,address));
        };

        // default destructor
        ~ VNS()=default;

        // functions
        void insert(const HostName& name, const IPAddress& address) {
        };

        bool remove(const HostName& name) {
            return false;
        };

        IPAddress lookup(const HostName& name) const {
            return 0;
        };

    private:
        vector<pairs> pairs_vector;
};

#endif