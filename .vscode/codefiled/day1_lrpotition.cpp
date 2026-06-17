//左右碰撞指针125 344 15 977 11 42
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <cmath>
using namespace std;
/*
回文串
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left <= right){
            while(left <= right && !isalnum(s[left])){
                left++;
            }
            while(left <= right && !isalnum(s[right])){
                right--;
            }
            if(left <= right){
                if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};
*/
/*
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};
*/
/*
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums){
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        for(int i = 0;i < nums.size() - 2;i++){
            if(i > 0&&nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    ret.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        right--;
                    }
                    left++;
                    right--;
                    continue;
                }
                if(sum < target){
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ret;
    }
};
*/
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size() - 1;
        while(left <= right){
            if(nums[left] * nums[left] > nums[right] * nums[right]){
                result[index] = nums[left] * nums[left];
                left++;
            } else {
                result[index] = nums[right] * nums[right];
                right--;
            }
            index--;
        }
        return result;
    }
};
*/
/*
盛水最多容器，双指针
短边移动，才能有可能增大面积
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
接雨水
计算总格数 - 黑格数(柱子占的格数)
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int count = 0;
        int black = height[left] + height[right];
        int leftmax = 0;
        int rightmax = 0;
        int lastheight = 0;
        int ret = 0;
        while(left < right){
            leftmax = max(leftmax,height[left]);
            rightmax = max(rightmax,height[right]);
            count += (min(leftmax,rightmax)-lastheight)*(right - left + 1);
            lastheight = min(leftmax,rightmax);
            if(leftmax < rightmax){
                while(left < right && leftmax >= height[left]){
                    left++;
                    black += height[left];
                }
            }else if(leftmax > rightmax){
                while(left < right && rightmax >= height[right]){
                    right--;
                    black += height[right];
                }
            }else{
                while(left < right && leftmax >= height[left]){
                    left++;
                    black += height[left];
                }
                while(left < right && rightmax >= height[right]){
                    right--;
                    black += height[right];
                }
            }
        }
        count += height[left] - lastheight;
        black -= height[left];
        ret = count - black;
        return ret;
    }
};
*/