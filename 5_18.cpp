#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int col = board[0].size();
        int row = board.size();
        vector<unordered_set<char>> rowset(row);
        vector<unordered_set<char>> colset(col);
        vector<unordered_set<char>> groupset(9);
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(board[i][j] != '.'){
                    if(rowset[i].count(board[i][j])){
                        return false;
                    }else{
                        rowset[i].insert(board[i][j]);
                    }
                    if(colset[j].count(board[i][j])){
                        return false;
                    }else{
                        colset[j].insert(board[i][j]);
                    }
                    int groupIndex = (i / 3) * 3 + j / 3;
                    if(groupset[groupIndex].count(board[i][j])){
                        return false;
                    }else{
                        groupset[groupIndex].insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
//解数独
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
    }
};