#ifndef MNS_H
#define MNS_H

#include "nameserverinterface.h"
#include <map>

using namespace std;

class MNS : public NameServerInterface {
    public:
        // constructors
        MNS()=default;

        VNS(std::pair pair) {
            pairs_vector.push_back(pair);};

        MNS(HostName name, IPAddress address) {
            map.insert(std::make_pair(name, address))
        };

        // default destructor
        ~ MNS()=default;

        // functions
        void insert(const HostName& name, const IPAddress& address) {
            map.emplace(name, address)
        };

        bool remove(const HostName& name) {
            return map.erase(name);
        };

        IPAddress lookup(const HostName& name) const {
            return 0;
        };

    private:
        map<HostName, IPAddress> map;
};

#endif