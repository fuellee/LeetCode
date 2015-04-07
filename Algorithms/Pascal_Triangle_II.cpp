#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        // c_n^m = C_n^{m-1} * (n-m+1)/m
        vector<int> res(n+1,1);
        for(size_t m=1; m<res.size(); ++m){
            res[m]=((long long) res[m-1])*(n-m+1)/m;
        }
        return res;
    }
};

int main() {
    Solution s;
    for(auto i:s.getRow(31)) cout<<i<<" ";
    // int a = 300540195;
    // cout<<a<<endl;
    return 0;
}
