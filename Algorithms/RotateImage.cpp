#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int rowN = matrix.size();
        if(rowN<=1) return;
        int colN = matrix[0].size();
        for(int row=0; row<rowN; ++row)
            for(int col=row+1; col<colN; ++col)
               swap(matrix[row][col],matrix[col][row]);
    }
};
