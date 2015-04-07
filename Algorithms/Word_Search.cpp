/*
 * Word_Search.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int rowN,colN;
    string word;
    int n; // size of word
    vector<vector<char> > board;
    bool search(int r, int c, int i) { 
        // i: index of current char in word
        // r: row
        // c: coloum
        if(i==n) return true;
        else if(r<0 || r>=rowN || c<0 || c>=colN || board[r][c]!=word[i] || board[r][c]=='#')
            return false;
        else {
                char ch = board[r][c];
                board[r][c] = '#'; // been, mark
                if(search(r-1,c ,i+1)) return true;
                board[r][c] = ch; // restore board

                ch = board[r][c];
                board[r][c] = '#';
                if(search(r,c-1 ,i+1)) return true;
                board[r][c] = ch; // restore board

                ch = board[r][c];
                board[r][c] = '#'; // been, mark
                if(search(r+1,c ,i+1)) return true;
                board[r][c] = ch; // restore board

                ch = board[r][c];
                board[r][c] = '#';
                if(search(r,c+1 ,i+1)) return true;
                board[r][c] = ch; // restore board

                return false;
        }
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        rowN = board.size();
        if(rowN==0) return false;
        colN = board[0].size();
        this->word = word;
        this->n = word.size();
        this->board = board;
        for (int row=0;row<rowN; ++row)
            for (int col=0; col<colN; ++col)
                if(search(row,col,0)) 
                    return true;
        return false;
    }
};
int main() {
    Solution s;   
    vector<vector<char> > board {{'a'}};
    cout<<s.exist(board,"a")<<endl;
    return 0;
}
