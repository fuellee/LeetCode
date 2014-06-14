/*
 * N_Queens_II.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int n;
    int total;
    // check feasibility incrementally
    // C: new pos 
    // solution[0] ~ solution[C-1] is feasible
    // check feasiblity after add solution[C]
    inline bool is_feasible_incr(const vector<int> &solution, const int &C) {
        for (int c = 0; c < C; ++c)
            if(solution[c]==solution[C] || abs(solution[C]-solution[c])==C-c)
                return false;
        return true;
    }
    // without & : 52ms use copies of `solution `
    // with &    : 16ms no copy, inplace
    void solve(vector<int> &solution, int C) {
        // solution[C] : not checked
        if(C==n) {
            total++;
            return;
        }
        else { // branch
            for (int r = 0; r < n; ++r) {
                solution[C]=r;
                if(is_feasible_incr(solution, C))
                    solve(solution, C+1);
            }
            return;
        }
    }
    int totalNQueens(int n) {
        total = 0;
        this->n=n;
        vector<int> solution(n);
        solve(solution,0);
        return total;
    }
};

int main() {
    Solution s; 
    cout<<s.totalNQueens(10)<<endl;
    return 0;
}
