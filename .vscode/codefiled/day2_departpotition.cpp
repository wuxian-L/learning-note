//分离指针 88 28 1768 392
#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>
using namespace std;
/*
合并两个有序数组，不占用额外空间
从后往前比较，减少移动开销
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1;
        int index2 = n - 1;
        int index = m + n - 1;
        while(index1 > -1 && index2 > -1){
            if(nums1[index1] > nums2[index2]){
                nums1[index] = nums1[index1]; 
                index1--;
                index--;
            }else{
                nums1[index] = nums2[index2];
                index--;
                index2--;
            }
        }
        while(index2 > -1){
            nums1[index] = nums2[index2];
            index--;
            index2--;
        }
    }
};
*/
/*
KMP算法
class Solution {
private:
    vector<int> getNext(string needle){
        if(needle.size() == 0){
            return {};
        }
        if(needle.size() == 1){
            return {-1};
        }
        vector<int> next(needle.size(), -1);
        for(int i = 1;i < needle.size();i++){
            int  j = next[i-1];
            while(j != -1 && needle[i-1] != needle[j]){
                j = next[j];
            }
            next[i] = j + 1;
        }
        return next;
    }
public:
    int strStr(string haystack, string needle) {
        vector<int> next = getNext(needle);
        int j = 0;
        int i = 0;
        while(i < haystack.size() && j < needle.size()){
            while(j!= -1 && haystack[i] != needle[j]){
                j = next[j];
            }
            j++;
            i++;
        }
        return j == needle.size() ? i - j : -1;
    }
};
*/
/*
交替合并字符串
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int index1 = 0;
        int index2 = 0;
        while(index1 < word1.size() && index2 < word2.size()){
            result += word1[index1];
            result += word2[index2];
            index1++;
            index2++;
        }
        if(index1 < word1.size()){
            result += word1.substr(index1);
        }
        if(index2 < word2.size()){
            result += word2.substr(index2);
        }
        return result;
    }
};
*/
/*
判断s是否是t的子序列，可以不连续
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index1 = 0;
        int index2 = 0;
        while(index1 < s.size() && index2 < t.size()){
            if(s[index1] == t[index2]){
                index1++;
            }
            index2++;
        }
        return index1 == s.size();
    }
}; 
*/