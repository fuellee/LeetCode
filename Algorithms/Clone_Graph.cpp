/*
 * Clone_Graph.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    typedef UndirectedGraphNode N;
    unordered_map<N*,N*> old2new;
    queue<N*> Q;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *graph) {
        if(graph==nullptr) return nullptr;

        Q.push(graph);
        old2new[graph]=new N(graph->label);
        while(!Q.empty()) {
            auto curN = Q.front(); Q.pop();
            auto &neighbors = curN->neighbors;
            auto &NewNeighors = old2new[curN]->neighbors;
            for(auto &neighbor: neighbors) {
                if(old2new.find(neighbor)==old2new.end()) {
                    auto NewNeighor = new N(neighbor->label);
                    old2new[neighbor]=NewNeighor;
                    NewNeighors.push_back(NewNeighor);
                    Q.push(neighbor);
                }
                else
                    NewNeighors.push_back(old2new[neighbor]);
            }
        }

        return old2new[graph];
    }
};

int main() {
    
    return 0;
}
