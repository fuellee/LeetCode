/*
 * Container_With_Most_Water.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        int L=0, R=height.size()-1, maxWater=0; 
        while(L<R){
            int barH=min(height[L],height[R]);
            int water = barH*(R-L);
            maxWater = max(maxWater, water);
            if(height[L]<height[R]) L++;
            else R--;
        }
        return maxWater;
    }
};
