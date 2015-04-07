#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <functional>
using namespace std;
class Solution {
    map<string,function<int(int&,int&)> > ops {{"+", [](int &l,int &r){return l+r;}},
                                               {"-", [](int &l,int &r){return l-r;}},
                                               {"*", [](int &l,int &r){return l*r;}},
                                               {"/", [](int &l,int &r){return l/r;}}};
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> S;
        for(auto e : tokens)  {
            if(ops.find(e)!=ops.end()) {
                int r = S.top(); S.pop();
                int l = S.top(); S.pop();
                S.push(ops[e](l,r));
            }
            else
                S.push(stoi(e));
        }
        return S.top();
    }

};
int main() {
    Solution s;
    vector<string> t1{"2", "1", "+", "3", "*"};
    cout<<s.evalRPN(t1)<<endl;
    vector<string> t2{"4", "13", "5", "/", "+"};
    cout<<s.evalRPN(t2)<<endl;
    vector<string> t3{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<s.evalRPN(t3)<<endl;
    return 0;
}
