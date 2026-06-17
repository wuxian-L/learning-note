// 一维动态规划509 53 198 300 139 152
#include <bits/stdc++.h>
using namespace std;
/*
//斐波那契数列,动态规划，时间复杂度O(n)，空间复杂度O(1)
class Solution {
private:
    vector<int> pretwo = {0,1};
public:
    int fib(int n) {
        if(n == 0 || n == 1){
            return pretwo[n];
        }
        for(int i = 2;i <= n;i++){
            int temp = pretwo[1];
            pretwo[1] = pretwo[0] + pretwo[1];
            pretwo[0] = temp;
        }
        return pretwo[1];
    }
};
*/
/*
// 最大子数组和
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0];
        int maxSumEnd = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxSumEnd = max(maxSumEnd + nums[i], nums[i]);
            maxSum = max(maxSum, maxSumEnd);
        }
        return maxSum;
    }
};
*/
/*
// 打家劫舍
// f(n) = max(f(n-1),f(n-2)+nums[n])
class Solution
{
private:
    vector<int> maxMoney_index = {0, 0};//f(n-2) f(n-1)
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int maxMoney = nums[0];
        maxMoney_index[0] = nums[0];
        maxMoney_index[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++){
            int temp = maxMoney_index[1];
            maxMoney_index[1] = max(maxMoney_index[1], maxMoney_index[0] + nums[i]);
            maxMoney_index[0] = temp;
        }
        return maxMoney_index[1];
    }
};
*/
/*
//最长递增子序列
//f(n) = max(f) if nums[n] > nums[n-1]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int maxLength = 1;
        vector<int> maxLength_index(nums.size(),1);
        for(int i = 1;i < nums.size();i++){
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j]){
                    maxLength_index[i] = max(maxLength_index[i],maxLength_index[j]+1);
                }
            }
            maxLength = max(maxLength,maxLength_index[i]);
        }
        return maxLength;
    }
};
//贪心 + 二分查找
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1;
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        //d[i]表示长度为i的最长递增子序列的末尾元素的最小值
        vector<int> d(n+1,0);
        d[len] = nums[0];
        for(int i = 1;i < n;i++){
            if(nums[i] > d[len]){
                d[++len] = nums[i];
            }else{
                int left = 1;
                int right = len;
                int pos = 0;
                while(left <= right){
                    int mid = (left + right) / 2;
                    if(d[mid] < nums[i]){
                        pos = mid;
                        left = mid + 1;
                    }else{
                        right = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
*/
/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < i;j++){
                if(dp[j] && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j)) != wordDict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
*/
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxmultiply = nums[0];
        int minmultiply = nums[0];
        int result = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(nums[i] < 0){
                swap(maxmultiply,minmultiply);
            }
            maxmultiply = max(maxmultiply * nums[i],nums[i]);
            result = max(result,maxmultiply);
            minmultiply = min(minmultiply * nums[i],nums[i]);
        }
        return result;
    }
};
*/





















