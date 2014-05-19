/*
 * Merge_Intervals.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.size()==0) return {newInterval};
        
        vector<Interval>::iterator pos;
        for(pos=intervals.begin();pos<intervals.end() && pos->start<newInterval.start; ++pos);
        intervals.insert(pos,newInterval);
        vector<Interval> res;
        int start = intervals[0].start, end = intervals[0].end;
        for(auto &itv:intervals){
            if(itv.start>end) { // __ __
                res.push_back(Interval(start,end));
                start = itv.start; end = itv.end;
            }
            else if(itv.end>end) { //  ---===──
                end = itv.end;
            }
        }
        if(res.empty() || end>res[res.size()-1].end)
            res.push_back(Interval(start,end));
        return res;
    }
};
int main() {
    Solution s;    
    // vector<Interval> intervals {Interval(1 ,3 ),
    //                             Interval(2 ,6 ),
    //                             Interval(8 ,10),
    //                             Interval(15,18)};
    // vector<Interval> intervals {Interval(1 ,3 )};
    // vector<Interval> intervals {Interval(1 ,3 ),
    //                             Interval(1 ,3 )};
    // vector<Interval> intervals {Interval(1 ,4 ),
    //                             Interval(2 ,3 )};

    vector<Interval> intervals;
    for(auto &itv: s.insert(intervals,{5,7}))
        cout<<"["<<itv.start<<","<<itv.end<<"]";
    return 0;
}
