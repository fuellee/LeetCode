/*
 * Gas_Station.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size(); // N gas stations
        for(int start=0; start<N; start++) {
            int carGas = 0;
            for(int i=start ; i<start+N; i++) {
                carGas += gas[i%N];
                carGas -= cost[i%N];
                if(carGas<0) break;
            }
            if(carGas>=0) return start;
        }
        return -1;
    }
};
