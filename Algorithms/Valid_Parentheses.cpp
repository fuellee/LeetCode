#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        for(auto c: s)
            switch(c) {
                case '{':
                    Stack.push('}'); break; 
                case '(':
                    Stack.push(')'); break; 
                case '[':
                    Stack.push(']'); break; 
                default:
                    if(Stack.empty())
                        return false;
                    else if(c==Stack.top())
                        Stack.pop();
                    else return false;
            }
        return Stack.empty();
    }
};

int main() {
    Solution s;
    cout<<(s.isValid(")")==0)<<endl;
    cout<<(s.isValid("())")==0)<<endl;
    cout<<(s.isValid("()")==1)<<endl;
    cout<<(s.isValid("([]{()})")==1)<<endl;
    return 0;
}
