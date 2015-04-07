#include <foobee/print.hpp>
#include <climits>
using namespace std;
// Find Minimum in Rotated Sorted Array 
// duplicates are allowed
// only 1 rotation
// same with `Find_Minimum_in_Rotated_Sorted_Array.cpp`
class Solution {
public:
    int m = INT_MAX;
    int findMin(vector<int> &num, int l, int r) {
        if(l==r) // singleton set
            return num[l];
        else if(l>r || num[l]<num[r]) // order segmentation
            return min(m,num[l]);
        else { // have a pivot in 
            int mid = (l+r)/2;
            return min(findMin(num,l,mid),findMin(num,mid+1,r));
        }
    }
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size()-1);
    }
};

int main() {
    vector<int> v = {1};
    Solution s;
    cout<<s.findMin(v);
    return 0;
}
