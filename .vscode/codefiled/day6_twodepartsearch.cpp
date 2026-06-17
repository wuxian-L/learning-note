//二分查找 704 35 34 33 69
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <cmath>
#include<deque>
#include<unordered_set>
using namespace std;
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int index = ( left + right )/2;
            if(nums[index] == target){
                return index;
            }else if(nums[index] > target){
                right=index - 1;
            }else{
                left = index + 1;
            }
        }
        return -1;
    }
};
*/
/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;
        while(left <= right){
            mid = left + (right - left)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
*/
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        vector<int> ret;
        while(left <= right){
            mid = left + (right - left)/2;
            if(nums[mid] == target){
                ret.push_back(mid);
                break;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        if(!ret.empty()){
            int num = ret[0];
            ret.push_back(num);
            int index1 = mid - 1;
            int index2 = mid + 1;
            while( index1 >= 0 && nums[index1] == target){
                ret[0] = index1;
                index1--;
            }
            while(index2 < nums.size() && nums[index2] == target){
                ret[1] = index2;
                index2++;
            }
            return ret;
        }
        return {-1,-1};
    }
};
*/
/*
//一半一半找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            if(nums[left] <= nums[right]){//进入有序序列
                while(left <= right){
                    int mid = left + ( right - left )/2;
                    if(nums[mid] == target){
                        return mid;
                    }else if(target < nums[mid]){
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                    }
                }
                return -1;
            }
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[left] <= nums[mid]){
                //左半部有序
                if(target < nums[left] || target > nums[mid]){//左半部没有
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }else{
                //右半部有序
                if(target > nums[right] || target < nums[mid]){//右半部没有
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
*/
/*
class Solution {
public:
    int mySqrt(int x) {
        //？!牛牛！？
        if(x <= 1){
            return x;
        }
        double a = x;
        double axis_x = x/2;//start
        while(true){
            double temp = axis_x;
            double d = axis_x/2 - a/(2*axis_x);
            axis_x = axis_x - d;
            double delta = abs(axis_x - temp);
            if(delta < 1e-2){
                return (int)axis_x;
            }
        }
        return axis_x;
    }
};
*/









