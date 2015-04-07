#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int WordStart=0,WordEnd=-1,i=0;
        bool inWord=false;
        for(i=0; s[i]!='\0'; ++i){
            if(s[i]==' ') {
                if(inWord) {
                    WordEnd=i-1;
                    inWord =false;
                } 
            }
            else { // current char is alpha-numerical
                if(not inWord) {
                    WordStart=i; 
                    inWord = true;
                }
            }
        }
        if(inWord) WordEnd=i-1;
        return WordEnd-WordStart+1;
    }
    // int lengthOfLastWord(const char *s) {
    //     int length = strlen(s);
    //     for (length--; length >= 0 && s[length] == ' '; length--) ;
    //     int res = 0;
    //     for (int i = length; i >= 0 && s[i] != ' '; i--, res++) ;
    //     return res;

    // }
};

int main() {
    Solution s;
    cout<<s.lengthOfLastWord("")<<endl;
    cout<<s.lengthOfLastWord(" asf asdf asdff")<<endl;
    cout<<s.lengthOfLastWord(" asf ")<<endl;
    cout<<s.lengthOfLastWord("asf ")<<endl;
    cout<<s.lengthOfLastWord("asf")<<endl;
    return 0;
}
