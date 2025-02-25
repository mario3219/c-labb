#ifndef MNS_H
#define MNS_H

#include "nameserverinterface.h"
#include <map>

using namespace std;

class MNS : public NameServerInterface {
    public:
        // constructors
        MNS()=default;

        MNS(std::pair<HostName, IPAddress> pair) {
            mappen.insert(pair);};

        MNS(HostName name, IPAddress address) {
            mappen.insert(std::make_pair(name, address));
        };

        // default destructor
        ~ MNS()=default;

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
        map<HostName, IPAddress> mappen;
};

#endif