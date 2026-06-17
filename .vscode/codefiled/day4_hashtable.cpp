//哈希表 1 49 128
#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i = 0;i < nums.size();i++){
            if(hash.find(target - nums[i])!=hash.end()){
                return {hash[target - nums[i]],i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
*/
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        vector<vector<string>> result;
        for(string str: strs){
            string key = str;
            sort(key.begin(),key.end());
            hash[key].push_back(str);
        }
        for(auto item: hash){
            result.push_back(item.second);
        }
        return result;
    }
};
极致性能
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto arrayHash = [fn = hash<uint8_t>{}] (const array<uint8_t, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, uint8_t num) {
                return (acc << 1) ^ fn(num);
            });
        };

        vector<vector<string>> ans;
        unordered_map<array<uint8_t, 26>, size_t, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<uint8_t, 26> counts{};
            uint8_t length = str.length();
            for (uint8_t i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            size_t idx;
            if (mp.count(counts)) {
                idx = mp[counts];
            } else {
                idx = ans.size();
                ans.push_back(vector<string>());
                mp[counts] = idx;
            }
            ans[idx].push_back(str);
        }
        return ans;
    }
};
*/
/*
连续序列
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //unordered_set<int> exist(nums.begin(), nums.end());
        unordered_map<int,int> hash;
        int maxlen = 0;
        for(int num: nums){
            if(hash.find(num) == hash.end()){
                hash[num] = 1;
            }
        }
        for(auto item: hash){
            int num = item.first;
            if(hash.find(num - 1) != hash.end()){
                continue;
            }
            int currentnum = num;
            int currentlen = 1;
            while(hash.find(currentnum + 1) != hash.end()){
                currentnum++;
                currentlen++;
            }
            maxlen = max(maxlen, currentlen);
        }
        return maxlen;
    }
};

