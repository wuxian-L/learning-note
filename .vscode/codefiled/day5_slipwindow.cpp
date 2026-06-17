// 滑动窗口 239 3 438 76 209 219
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <cmath>
#include<deque>
#include<unordered_set>
using namespace std;
/*
//普通数组实现滑动窗口，超出时间限制
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int max = 0;
        int maxindex = 0;
        vector<int> result;
        for(int i = 0;i < k;i++){
            if(nums[i] > max){
                max = nums[i];
                maxindex = i;
            }
        }
        result.push_back(max);
        for(int i = k;i < nums.size();i++){
            if(nums[i] > max){
                max = nums[i];
                maxindex = i;
            } else if(maxindex == i - k){
                max = nums[i-k+1];
                maxindex = i-k+1;
                for(int j = i-k+2;j <= i;j++){
                    if(nums[j] > max){
                        max = nums[j];
                        maxindex = j;
                    }
                }
            }
            result.push_back(max);
        }
        return result;
    }
};
//双端队列实现滑动窗口，时间复杂度O(n)，空间复杂度O(k)
//k很大时，空间复杂度仍为O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k <= 0){
            return {};
        }
        if(k == 1){
            return nums;
        }
        vector<int> result;
        deque<int> deq;//存储元素的索引，保证队列中的元素是递减的
        for(int i = 0 ;i < nums.size();i++){
            if(!deq.empty() && deq.front() == i - k){
                deq.pop_front();
            }
            //移除队列中比当前元素小的元素，因为它们不可能成为窗口的最大值
            while(!deq.empty() && nums[deq.back()] < nums[i]){
                deq.pop_back();
            }
            deq.push_back(i);
            if(i >= k - 1){
                result.push_back(nums[deq.front()]);
            }
        }
        return result;
    }
};
*/
/*
最长不含重复字符的子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int leftindex = 0;
        int ret = 0;
        for(int right = 0;right < s.size();right++){
            for(int i = leftindex;i < right;i++){
                if(s[i] == s[right]){
                    leftindex = i + 1;
                    break;
                }
            }
            ret = max(ret,right - leftindex + 1);
        }
        return ret;
    }
};
*/
/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()){
            return {};
        }
        unordered_map<char, int> charset;
        unordered_map<char, int> windowset;
        vector<int> result;
        for(int i = 0;i < p.size();i++){
            windowset[s[i]]++;
            charset[p[i]]++;
        }
        if(windowset == charset){
            result.push_back(0);
        }
        for(int i = p.size();i < s.size();i++){
            windowset[s[i-p.size()]]--;
            if(windowset[s[i-p.size()]] == 0){
                windowset.erase(s[i-p.size()]);
            }
            windowset[s[i]]++;
            if(windowset == charset){
                result.push_back(i - p.size() + 1);
            }
        }
        return result;
    }
};
*/
/*
最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128,0);
        int left = 0;
        int right = 0;
        int start = 0;
        int valid = 0;
        int require = 0;
        int min_len = INT_MAX;
        for(char c: t){
            need[c]++;
        }  
        for(int cnt: need){
            if(cnt > 0){
                require++;
            }
        }
        while(right < s.size()){
            char c = s[right];
            right++;
            if(need[c] > 0){//只有需要的字符才加入窗口
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }
            while(valid == require){//当窗口满足条件时，尝试缩小窗口
                if(right - left < min_len){
                    min_len = right - left;
                    start = left;
                }
                char l = s[left];
                left++;
                if(need[l] > 0){//只有需要的字符才修改窗口
                    if(window[l] == need[l]){
                        valid--;
                    }
                    window[l]--;
                }
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
*/
/*
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int min_len = INT_MAX;
        int sum = 0;
        while(right < nums.size()){
            sum+=nums[right++];
            while(sum >= target){
                min_len = min(min_len,right - left);
                sum-=nums[left++];
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
*/
/*
存在重复元素
//哈希表
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int min_delta = INT_MAX;
        for(int i = 0;i < nums.size(); i++){
            if(hash.find(nums[i]) != hash.end()){//若数字出现过
                if(i - hash[nums[i]] <= min_delta){
                    min_delta = i - hash[nums[i]];
                    hash[nums[i]] = i;//更新坐标
                }
            }else{
                hash[nums[i]] = i;
            }
        }
        return min_delta <= k ? true : false;
    }
};
*/
//滑动窗口?
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0;
        int right = 1;
        while(right - left < k){

        }
    }
};







