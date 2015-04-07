#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict){
        int len=s.size();
        vector<bool> DP(len+1,false);
        DP[0]=true;
        for(int i=1;i<=len;++i){
            for(int j=i-1; j>=0; --j)
                // DP[j]: s.substr(0,j-1) is valid
                // dict.find(s.substr(j,i-j))!=dict.end()): s.substr(j,i-j) is valid
                // thus, s.substr(0,i-1) is valid
                if(DP[j] && dict.find(s.substr(j,i-j))!=dict.end()) {
                    DP[i] = true;
                    break;
                }
        }
        return DP[len];
    }
};

int main() {
    Solution s;
    unordered_set<string> dict {"aa","b"};
    cout<<(s.wordBreak("a",dict)==false)<<endl;
    cout<<(s.wordBreak("aa",dict)==true)<<endl;
    cout<<(s.wordBreak("aaa",dict)==false)<<endl;
    cout<<(s.wordBreak("aba",dict)==false)<<endl;
    cout<<(s.wordBreak("aab",dict)==true)<<endl;
    cout<<(s.wordBreak("baa",dict)==true)<<endl;
    return 0;
}
