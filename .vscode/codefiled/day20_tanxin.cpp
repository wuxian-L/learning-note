//贪心121 55 122
#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int index = 0;
        int ret = 0;
        while(index < prices.size()){
            int maxindex = -1;
            int maxprice = INT_MIN;
            index++;
            for(int i = index;i < prices.size();i++){
                if(prices[i] >= maxprice){
                    maxindex = i;
                    maxprice = prices[i];
                }
            }
            index = maxindex;
            int minindex = -1;
            int minprice = maxprice;
            for(int i = 0;i < maxindex;i++){
                if(prices[i] < minprice){
                    minindex = i;
                    minprice = prices[i];
                }
            }
            if(minindex == -1){
                continue;
            }
            int temp = maxprice - minprice;
            ret = temp > ret? temp : ret; 
        }
        return ret;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int p = 0;
        int q = n-1;
        int l = prices[p],r = prices[q];
        int maxprice = max(0,r-l);
        while(p < q){
            int j = r - prices[p+1];//右移
            int k = prices[q-1]-l;//左移
            if(j > k){
                p++;
            }else{
                q--;
            }
            l = min(l,prices[p]);
            r= max(r,prices[q]);
            maxprice = max(maxprice,r-l);
        }
        return maxprice;
    }
};
*/
/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currentmax = nums[0];
        int currentindex = 0;
        for(int i = 0;i < nums.size();i++){
            if(currentmax >= nums.size()-1){
                return true;
            }
            if(i > currentmax){
                return false;
            }
            if(currentmax >= i){
                int maymax = i + nums[i];
                currentmax = maymax > currentmax?maymax:currentmax;
            }
        }
        return false;
    }
};
*/
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> nprices(n + 2,0);
        nprices[0] = INT_MAX;
        nprices[n+1] = INT_MIN;
        for(int i = 1;i <= n;i++){
            nprices[i] = prices[i-1];
        }
        bool have = false;
        int money = 0;
        for(int i = 1;i <= n;i++){
            if(!have && nprices[i] <= nprices[i-1] && nprices[i] <= nprices[i+1]){
                money -= nprices[i];
                have = true;
            }
            if(have && nprices[i]>= nprices[i-1] && nprices[i] >= nprices[i+1]){
                money += nprices[i];
                have = false;
            }
        }
        return money;
    }
};
*/






