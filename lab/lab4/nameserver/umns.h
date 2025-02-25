#ifndef UMNS_H
#define UMNS_H

#include "nameserverinterface.h"
#include <unordered_map>

using namespace std;

class UMNS : public NameServerInterface {
    public:
        // constructors
        UMNS()=default;

        UMNS(std::pair<HostName, IPAddress> pair) {
            mappen.insert(pair);};

        UMNS(HostName name, IPAddress address) {
            mappen.insert(std::make_pair(name, address));
        };

        // default destructor
        ~ UMNS()=default;

        // functions
        void insert(const HostName& name, const IPAddress& address) {
            mappen.emplace(name, address);
        };

        bool remove(const HostName& name) {
            return mappen.erase(name) > 0;
        };

        IPAddress lookup(const HostName& name) const {
            auto it = mappen.find(name);
            return (it != mappen.end()) ? it->second : NON_EXISTING_ADDRESS;
        }

    private:
        unordered_map<HostName, IPAddress> mappen;
};

#endif