#include <FooBee/out>
using namespace std;
class Solution {
    void com(vector<int> acc, int i, const int &k, const int &n,vector<vector<int> > &res) {
        if(int(acc.size())==k)
            res.push_back(acc);
        else if(i<=n){
            com(acc,i+1,k,n,res);
            acc.push_back(i);
            com(acc,i+1,k,n,res);
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        com({},1,k,n,res);
        return res;
    }
};

int main() {
    Solution s;
    cout<<s.combine(5,3)<<endl;
    return 0;
}
