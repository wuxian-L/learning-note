//编程基础1 11 560 53 14 209
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndex;//数值 - 索引
        for(int i =0;i<nums.size();i++){
            int x = target - nums[i];
            if(numIndex.find(x) != numIndex.end()){
                return {numIndex[x],i};
            }
            numIndex[nums[i]] = i;
        }
        return {};
    }
};
*/
/*
class Solution{
    public:
        int maxArea(vector<int>& height){
            int left = 0;
            int right = height.size()-1;
            int maxarea = 0;
            while(left < right){
                int currentarea = min(height[left],height[right])*(right-left);
                maxarea = max(maxarea,currentarea);
                if(height[left] < height[right]){
                    left++;
                }else{
                    right--;
                }
            }
            return maxarea;
        }
};
*/
/*
//哈希表+前缀和
//子数组是连续的，一定等于前缀和的差值
//哈希表记录前缀和出现的次数
//如果当前前缀和减去k 得到的前缀和 在哈希表中出现过，说明存在子数组的和为k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int,int> sumCount;
        sumCount[0] = 1;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            if(sumCount.find(sum-k)!=sumCount.end()){
                count += sumCount[sum - k];
            }
            sumCount[sum]++;
        }
        return count;
    }
};
*/
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int minpre = 0;
        int maxsum = nums[0];
        for(int i = 0;i < nums.size();i++){
            pre += nums[i];
            maxsum = max(maxsum,pre - minpre);
            minpre = min(minpre, pre);
        }
        return maxsum;
    }
};
*/
/*
class Solution {
private:
    string CompareTwoString(string str1,string str2){
        int mostlength = str2.size();
        for(int i = 0;i < mostlength;i++){
            if(str1[i] != str2[i]){
                return str2.substr(0,i);
            }
        }
        return str2;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)
            return strs[0];
        string CommonPrefix = "";
        CommonPrefix = CompareTwoString(strs[0],strs[1]);
        for(int index = 0;index < strs.size();index++){
            CommonPrefix = CompareTwoString(CommonPrefix,strs[index]);
        }
        return CommonPrefix;
    }
};
*/
/*
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ret = 0;
        int sum = 0;
        while(sum < target && right < nums.size()){
            sum += nums[right];
            right++;
        }
        if(sum < target){
            return 0;
        }else{
            ret = right - left;
        }
        while(left < right && right <= nums.size()){
            if(sum - nums[left] >= target){
                sum -= nums[left];
                left++;
                ret = min(ret,right - left);
            }else{
                if(right == nums.size()){
                    break;
                }
                sum += nums[right];
                right++;
            }
        }
        return ret;
    }
};
*/
