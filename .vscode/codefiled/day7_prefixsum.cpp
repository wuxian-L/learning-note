//前缀和 560 209 238
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
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            if(map.find(sum - k) != map.end()){
                count+=map[sum-k];
            }
            map[sum]++;//不能在if前，顺序很重要，why？
            //因为非空序列,保证至少包含i位置元素
        }
        return count;
    }
};
*/
// # 1 2 3    4 5 6 7 8
//       sum
/*
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int min_len = INT_MAX;
        vector<int> presum(nums.size() + 1,0);//presum[i]不包括nums[i]
        for(int i =1;i < nums.size()+1;i++){
            presum[i] = presum[i-1] + nums[i-1]; 
        }
        for(int i = 1;i < nums.size() + 1;i++){
            //在前i-1个中二分查找
            int left = 0;
            int right = i;
            int cursum = presum[i];
            min_len;
            while(left <=  right){
                int mid = left + (right - left)/2;
                int midsum = presum[mid];
                if(cursum - midsum >= target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            if(right >= 0 && cursum - presum[right] >= target){
                min_len =min(min_len,i-right);
            }
        }
        return min_len == INT_MAX? 0 : min_len;
    }
};
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> right_mul(length,0);
        vector<int> left_mul(length,0);
        //不包含nums[i]
        left_mul[0] = 1;
        right_mul[nums.size() - 1] = 1;
        for(int i = 1;i < nums.size();i++){
            left_mul[i] = nums[i-1] * left_mul[i-1];
            right_mul[length - 1 - i] = nums[length -i] * right_mul[length - i];
        }
        vector<int> ret(nums.size(),0);
        for(int i = 0;i < nums.size();i++){
            ret[i] = left_mul[i] * right_mul[i];
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);
        answer[0] = 1;
        for(int i = 1;i < length;i++){
            answer[i] = nums[i - 1] * answer[i-1];
        }//返回值，也是临时前缀积
        int R = 1;
        for(int i = length - 1;i >= 0;i--){
            answer[i] = answer[i] * R;
            R *= nums[i];//R 无需数组保存
        }//实现空间复杂度O(1)
        return answer;
    }
};











