//二维动态规划62 118 63 72 1143 221
#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    //f(m,n) = f(m-1,n) + f(m,n-1)
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0;i < m;i++){
            dp[i][0] = 1;
        }
        for(int j = 0;j < n;j++){
            dp[0][j] = 1;
        }
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
class Solution{
public:
    int uniquePaths(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i > 0){
                    dp[i][j] += dp[i-1][j];
                }
                if(j > 0){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
*/
/*
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int h = numRows;
        vector<vector<int>> result(h);
        for(int i = 0;i < h;i++){
            result[i].resize(i+1,1);
            for(int j = 1;j < i ;j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        return result;
    }
};
*/
/*
//不同路径II
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        dp[0][0] = 1;
        for(int i = 0;i < obstacleGrid.size();i++){
            for(int j = 0;j < obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j] ==1){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 0;i < obstacleGrid.size();i++){
            for(int j = 0;j < obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j] ==1){
                    continue;
                }
                if(i > 0){
                    dp[i][j] += dp[i-1][j];
                }
                if(j > 0){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
*/
//编辑距离
/*
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i = 0;i <= m;i++){
            dp[i][0] = i;
        }
        for(int j = 0;j <= n;j++){
            dp[0][j] = j;
        }
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
*/
/*
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));//公共
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
*/
/*
//最大正方形
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int maxsqlen = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == '1'){
                    dp[i+1][j+1] = 1;
                }
            }
        }
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(dp[i][j] == 1){
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                    maxsqlen = max(maxsqlen,dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
};
*/















