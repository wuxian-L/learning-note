//回溯46 77 78
#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
private:
    void backtrack(vector<vector<int>>& res,vector<int>& nums,int first,int len){
        if(first == len){
            res.push_back(nums);
            return;
        }
        for(int i = first;i < len;i++){
            swap(nums[i],nums[first]);//交换，固定第一个数
            backtrack(res,nums,first + 1,len);//递归，固定下一个数
            swap(nums[i],nums[first]);//回退，恢复原数组
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res,nums,0,nums.size());
        return res;
    }
};
*/
/*
class Solution {
private:
    void backtrack(vector<int>& path,vector<vector<int>>& res,vector<int>& nums,int start,int k){
        if(path.size() == k){//树深
            res.push_back(path);
            return;
        }
        for(int i =start;i < nums.size();i++){//树宽
            path.push_back(nums[i]);//组合不考虑顺序，所以不交换，直接固定第一个数
            backtrack(path,res,nums,i + 1,k);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);
        for(int i = 0;i < n;i++){
            nums[i] = i + 1;
        }
        vector<vector<int>> res;
        vector<int> path;
        backtrack(path,res,nums,0,k);
        return res;
    }
};
*/
class Solution {
private:
    void backtrack(vector<int>& path,vector<vector<int>>& res,vector<int>& nums,int start){
        res.push_back(path);
        for(int i = start;i < nums.size();i++){
            path.push_back(nums[i]);
            backtrack(path,res,nums,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(path,res,nums,0);
        return res;
    }
};