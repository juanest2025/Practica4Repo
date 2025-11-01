#include "Network.h"

void Network::add_router(const string &name) {
    if (adj.find(name) == adj.end()) adj[name] = {};
}

void Network::remove_router(const string &name) {
    adj.erase(name);
    for (auto &p : adj) p.second.erase(name);
}

void Network::add_link(const string &a, const string &b, int cost) {
    add_router(a);
    add_router(b);
    adj[a][b] = cost;
    adj[b][a] = cost;
}

void Network::remove_link(const string &a, const string &b) {
    if (adj.count(a)) adj[a].erase(b);
    if (adj.count(b)) adj[b].erase(a);
}

void Network::print_neighbors(const string &name) const {
    if (!adj.count(name)) {
        cout << "Router '" << name << "' not found.\n";
        return;
    }
    cout << "Neighbors of " << name << ":\n";
    for (auto &nb : adj.at(name))
        cout << "  " << nb.first << " (cost=" << nb.second << ")\n";
}
