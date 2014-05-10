#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > M ={{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > M(n,vector<int>(n));
        int x=1;
        for(int padding=0; padding<(n+1)/2; ++padding){
            for(int col=padding; col<n-padding; ++col)
                M[padding][col]=x++;
            for(int row=padding+1; row<n-padding; ++row)
                M[row][n-1-padding]=x++;
            for(int col=n-2-padding; col>=padding; --col)
                M[n-1-padding][col]=x++;
            for(int row=n-2-padding; row>=padding+1; --row)
                M[row][padding]=x++;
        }
        return M;
    }
};

int main() {
    Solution s;
    for(auto v:s.generateMatrix(3)){
        for(auto e: v)
            cout<<e<<" ";
        cout<<endl;
    }
    return 0;
}
