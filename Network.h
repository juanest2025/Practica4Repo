#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
#include <algorithm>
using namespace std;


class Network {
private:
    map<string, map<string,int>> adj; // router -> (neighbor -> cost)

public:
    void add_router(const string &name);
    void remove_router(const string &name);
    void add_link(const string &a, const string &b, int cost);
    void remove_link(const string &a, const string &b);
    void print_neighbors(const string &name) const;
    pair<map<string,int>, map<string,string>> dijkstra(const string &src) const;
    pair<vector<string>, int> shortest_path(const string &src, const string &dst) const;
    void print_routing_table(const string &router) const;
    void print_graph() const;
    bool load_from_file(const string &filename);
    void create_random_small();
};


#endif
