#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int last = n-1, i=0;
        while(i<=last){
            if(A[i]==elem)
                A[i]=A[last--];
            else ++i;
        }
        return last+1;
    }
    // int removeElement(int A[], int n, int elem) {
    //     int cur=0;
    //     for(int i=0;i<n;++i)
    //         if(A[i]!=elem)
    //             A[cur++]=A[i];
    //     return cur;

    // }
};

int main() {
    Solution s;
    int A[] = {1,1,1,3,1};
    int newlen = s.removeElement(A,5,1);
    for(int i=0;i<newlen;++i)
        cout<<A[i]<<" ";
    return 0;
}
