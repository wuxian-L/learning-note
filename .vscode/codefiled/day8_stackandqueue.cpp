// 栈与队列20 394 739 239 224
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <cmath>
#include <deque>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;
/*
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '}'){
                stk.push(s[i]);
            }else{
                if(stk.empty()) return false;
                if((stk.top() == '(' && s[i] == ')') || (stk.top() == '[' && s[i] == ']') || (stk.top() == '{' && s[i] == '}')){
                    stk.pop();
                }else{
                    return false;
                }
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};
*/
/*
 */
/*
class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for(int i = 0;i < s.size();i++){
            if(s[i] == ']'){
                //计算重复字符
                string ts;
                while(stk.top()!='['){
                    ts += stk.top();
                    stk.pop();
                }
                reverse(ts.begin(),ts.end());
                stk.pop();
                //计算重复次数
                int bit = 1;
                int num = 0;
                while(!stk.empty() && isdigit(stk.top())){
                    num += bit*(stk.top() - 48);
                    bit *= 10;
                    stk.pop();
                }
                //计算字符串
                string addstr;
                for(int i = 0;i < num;i++){
                    addstr += ts;
                }
                //入栈
                for(int i = 0 ;i < addstr.size(); i++){
                    stk.push(addstr[i]);
                }
            }else{
                stk.push(s[i]);
            }
        }
        string ret;
        while(!stk.empty()){
            ret += stk.top();
            stk.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
*/
/*
//栈存下标
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temper_index;
        vector<int> answer;
        int delta_day = 0;
        for( int i = 0;i < temperatures.size();i++){
            while(!temper_index.empty() && temperatures[i] > temperatures[temper_index.top()]){
                int previousIndex = temper_index.top();
                answer[previousIndex] = i - previousIndex;
                temper_index.pop();
            }
            temper_index.push(i);
        }
        return answer;
    }
};
//暴力双循环 但 超时
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int i = 0;
        vector<int> answer;
        while(i < temperatures.size()){
            int j = i + 1;
            int num = 1;
            while(j<temperatures.size() && temperatures[j] <= temperatures[i]){
                num++;
                j++;
            }
            if(num < temperatures.size() - i){
                answer.push_back(num);
            }else{
                answer.push_back(0);
            }
            i++;
        }
        return answer;
    }
};
*/
/*
//滑动窗口最大值
//deque,双端队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxqueue;
        vector<int> answer;
        for(int i = 0;i < nums.size();i++){
            if(!maxqueue.empty() && maxqueue.front() == i - k){
                maxqueue.pop_front();
            }
            while(!maxqueue.empty() && nums[maxqueue.back()] < nums[i]){
                maxqueue.pop_back();
            }
            maxqueue.push_back(i);
            if(i >= k-1){
                answer.push_back(nums[maxqueue.front()]);
            }
        }
        return answer;
    }
};
*/
// 基本计算器
/*
class Solution
{
private:
    void compute(stack<int> &nums, stack<char> &signs)
    {
        char sign = signs.top();
        signs.pop();
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        int res;
        switch (sign)
        {
        case '+':
            res = num2 + num1;
            break;
        case '-':
            res = num2 - num1;
            break;
        default:
            break;
        }
        nums.push(res);
    }

public:
    int calculate(string s)
    {
        stack<int> nums;
        stack<char> signs;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == ' ')
                continue;
            if (isdigit(c))
            {
                int num = 0;
                while (i < s.size() && isdigit(s[i]))
                {
                    num = num * 10 + (int)(s[i] - '0');
                    i++;
                }
                i--;
                nums.push(num);
            }
            else
            {
                if (c == '(')
                {
                    signs.push(c);
                }
                else if (c == ')')
                {
                    while (!signs.empty() && signs.top() != '(')
                    {
                        compute(nums, signs);
                    }
                    signs.pop();
                }
                else if (c == '-')
                {
                    bool isUnary = true;
                    int j = i - 1;
                    while (j >= 0 && s[j] == ' ')
                        j--;
                    if (j >= 0)
                    {
                        char prev = s[j];
                        // 如果前面是数字或右括号，说明是减号
                        if (isdigit(prev) || prev == ')')
                        {
                            isUnary = false;
                        }
                    }

                    if (isUnary)
                    {
                        nums.push(0);
                    }
                    while (!signs.empty() && signs.top() != '(')
                    {
                        compute(nums, signs);
                    }
                    signs.push(c);
                }
                else
                {
                    while (!signs.empty() && signs.top() != '(')
                    {
                        compute(nums, signs);
                    }
                    signs.push(c);
                }
            }
        }
        while (!signs.empty())
        {
            compute(nums, signs);
        }
        return nums.top();
    }
};
*/