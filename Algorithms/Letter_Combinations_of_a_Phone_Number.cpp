#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

string n2str[]= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> product(vector<string> &pre,string &str){
        vector<string> res;
        for(auto s :pre)
            for(auto c : str)
                res.push_back(s+c);
        return res;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res = {""};
        for(auto c: digits)
            res = product(res,n2str[c-'0']);
        return res;
    }
int main() {
    for(auto str : letterCombinations("23"))
        cout<<str<<" ";
    cout<<endl;
    return 0;
}
