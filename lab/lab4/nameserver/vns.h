#ifndef VNS_H
#define VNS_H

#include "nameserverinterface.h"
#include <vector>
#include <algorithm>

using namespace std;

// create data structure for pairs
struct Pair{
    Pair(HostName name, IPAddress address):name(name),address(address) {}
    HostName name;
    IPAddress address;
};

class VNS : public NameServerInterface {
    public:
        // constructors
        VNS()=default;

        VNS(Pair pair) {
            pairs.push_back(pair);};
        
        VNS(HostName name, IPAddress address) {
            pairs.push_back(Pair(name,address));
        };

        // default destructor
        ~ VNS()=default;

        // functions
        void insert(const HostName& name, const IPAddress& address) {
            pairs.push_back(Pair(name,address));
        };

        bool remove(const HostName& name) {
            size_t before = pairs.size();
            
            pairs.erase(
                remove_if(pairs.begin(),pairs.end(),
                // lambda function, returns true if checked pair matches name
                [&name](const Pair& pair) {return pair.name == name;}
                ), pairs.end()
            );

            size_t after = pairs.size();
            
            // if the size of pairs vector is unchanged, removal has failed
            if (before != after) {
                return true;
            } return false;
        };

        IPAddress lookup(const HostName& name) const {

            auto found_pair = find_if(
                pairs.begin(), pairs.end(),
                // lambda function, returns true if checked pair matches name
                [&name](const Pair& pair) {return pair.name == name;}
            );

            // if the iterator reached the end, the pair doesn't exist
            if (found_pair != pairs.end()) {
                return found_pair->address;
            } return NON_EXISTING_ADDRESS;
        };

    private:
        vector<Pair> pairs;
};

#endif