//深度优先算法 200 695 79 /130 131 133 200 207 210 257 279 286 297 322 337 394 417 437 463 494 695
#include<bits/stdc++.h>
using namespace std;
//岛屿数量
/*
class Solution {
private:
    void dfs(vector<vector<char>>& grid,int i,int j){
        grid[i][j] = '0';
        if(i < grid.size() - 1 && grid[i + 1][j] == '1')dfs(grid,i + 1,j);
        if(i > 0 && grid[i - 1][j] == '1')dfs(grid,i - 1,j);
        if(j < grid[0].size() - 1 && grid[i][j + 1] == '1')dfs(grid,i,j + 1);
        if(j > 0 && grid[i][j - 1] == '1')dfs(grid,i,j - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
*/
/*
//695 岛屿的最大面积
class Solution {
private:
    void dfs(vector<vector<int>>& grid,int i,int j,int& size){
        grid[i][j] = 0;
        size++;
        if(i < grid.size() - 1 && grid[i + 1][j] == 1)dfs(grid,i + 1,j,size);
        if(i > 0 && grid[i - 1][j] == 1)dfs(grid,i - 1,j,size);
        if(j < grid[0].size() - 1 && grid[i][j + 1] == 1)dfs(grid,i,j + 1,size);
        if(j > 0 && grid[i][j - 1] == 1)dfs(grid,i,j - 1,size);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int size = 0;
                    dfs(grid,i,j,size);
                    maxArea = max(maxArea,size);
                }
            }
        }
        return maxArea;
    }
};
class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i ,int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1){
            return 0;
        }
        grid[i][j] = 2;
        return 1 + dfs(grid,i + 1,j) + dfs(grid,i - 1,j) + dfs(grid,i,j + 1) + dfs(grid,i,j - 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j]==1){
                    int area = dfs(grid,i,j);
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};
*/
/*
class Solution {
private:
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,string word,int& index,int i,int j){
        if(index == word.size())return;
        if(i < 0 || i >= board.size() || j < 0 || j >=board[0].size() 
        || visited[i][j] || board[i][j] != word[index])
            return;

        visited[i][j] = true;
        index++;
        int temp = index;
        if(index == word.size())return;
        dfs(board,visited,word,index,i + 1,j);
        if(index == word.size())return;
        index = temp;
        dfs(board,visited,word,index,i - 1,j);
        if(index == word.size())return;
        index = temp;
        dfs(board,visited,word,index,i,j + 1);
        if(index == word.size())return;
        index = temp;
        dfs(board,visited,word,index,i,j - 1);
        visited[i][j] = false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] != word[0])continue;
                int index = 0;
                dfs(board,visited,word,index,i,j);
                if(index == word.size())return true;
            }
        }
        return false;
    }
};
class Solution{
    static constexpr int DIRS[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    bool exist(vector<vector<char>>& board,string word){
        unordered_map<char,int> cnt;//统计每个字符出现的次数
        for(auto& row: board){
            for(auto& c: row){
                cnt[c]++;
            }
        }
        //优化，单词中某个字符出现的次数大于棋盘上该字符的出现次数
        //直接返回false
        unordered_map<char,int> word_cnt;
        for(char c: word){
            if(++word_cnt[c] > cnt[c]){
                return false;
            }
        }
        //优化，单词中第一个字符出现的次数大于最后一个字符的出现次数
        //反转单词，保证第一个字符出现的次数小于等于最后一个字符的出现次数，减少搜索次数
        //因为搜索是从第一个字符开始的，如果第一个字符出现的次数较多，搜索空间较大，反转后可以减少搜索空间
        //例如，单词是"AAAAB"，棋盘上有4个A和1个B，如果从A开始搜索，搜索空间较大，如果从B开始搜索，搜索空间较小
        if(cnt[word.back()] < cnt[word.front()]){
            reverse(word.begin(),word.end());
        }
        int m = board.size();
        auto dfs = [&](auto&& dfs,int i,int j,int k)->bool{
            if(board[i][j] != word[k]){
                return false;
            }
            if(k + 1 == word.size()){
                return true;
            }
            board[i][j] = '0';
            for(auto& [dx,dy]: DIRS){
                int x = i + dx;
                int y = j + dy;
                if(x >= 0 && x < m && y >= 0 && y < board[0].size() && dfs(dfs,x,y,k + 1)){
                    return true;
                }
            }
            board[i][j] = word[k];
            return false;
        };
        for(int i = 0;i < m;i++){
            for(int j = 0;j < board[0].size();j++){
                if(dfs(dfs,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
*/














