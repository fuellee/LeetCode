#include <foobee/print.hpp>
#include <climits>
using namespace std;
// Find Minimum in Rotated Sorted Array 
// no duplicates
// only 1 rotation
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

int findMin_(vector<int> &num) {

    int low=0, high=num.size()-1;

    while(high-low>1){
        //skip the same element, this would cause the O(n) run-time complexity. 
        while (high - low > 1 && num[low] == num[high]){
            low++;
        }
        //binary search
        int mid = low + (high-low)/2;
        //If the array is not rotated then return num[low]
        //Notes: checking the equal situation
        if (num[low] <= num[mid] && num[mid] <= num[high]){
            return num[low];
        }
        //move the high pointer to the middle, if sub-array from low to mid is rotated.
        if (num[low] > num [mid]){
            high = mid;
            continue;
        }
        // move the low pointer to the middle, if sub-array from mid to high is rotated.
        if (num[mid] > num[high]){
            low = mid;
            continue;
        }
    }
    
    // checking the edge case 
    if (high == low) return num[low];
    return num[low] < num[high] ? num[low] : num[high];

}

int main() {
    vector<int> v = {2,2,2,2,1,2};
    Solution s;
    cout<<s.findMin(v)<<endl;
    cout<<findMin_(v);
    return 0;
}
