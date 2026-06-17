//背包问题322 279 416
//用容量维度记录消耗，用物品维度记录决策
#include <bits/stdc++.h>
using namespace std;
//f(n) = min(f(n-k)) + 1
/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> fn(amount + 1,INT_MAX-1);
        fn[0] = 0;
        for(int i = 1;i <= amount;i++){
            for(int j = 0;j < coins.size();j++){
                if(i - coins[j] >= 0)
                    fn[i] = min(fn[i],fn[i-coins[j]] + 1);
            }  
        }
        return fn[amount] == INT_MAX-1?-1:fn[amount];
    }
};
*/
/*
//完全平方数
class Solution {
public:
    int numSquares(int n) {
        int sq = sqrt(n);
        vector<int> fn(n+1,INT_MAX - 1);
        fn[0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= sq;j++){
                if(i - j*j >= 0){
                    fn[i] = min(fn[i],fn[i-j*j]+1);
                }
            }
            if(i + sq*sq > n)sq--; 
        }
        return fn[n];
    }
};
*/
//分割等和子集
//f(n) = f(n-k) + k,k is available
/*
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return false;
        }
        int sum = accumulate(nums.begin(),nums.end(),0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if(sum & 1){//奇偶判断
            return false;
        }
        int target = sum/2;
        if(maxNum > target){
            return false;
        }
        //其中 dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个），
        //是否存在一种选取方案使得被选取的正整数的和等于 j
        //dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]] j>= nums[i]
        //dp[i][j] = dp[i-1][j]         j< nums[i]


        vector<vector<int>> dp(n,vector<int>(target + 1,0));
        for(int i = 0;i < n;i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i = 1;i < n; i++){
            int num = nums[i];
            for(int j = 1;j <= target;j++){
                if(j >= num){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-num];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }
};