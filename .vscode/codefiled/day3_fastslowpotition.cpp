//同向快慢指针283 27 26 19
#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>
using namespace std;
/*
283. 移动零
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int slow = 0;
       for(int fast = 0;fast < nums.size();fast++){
           if(nums[fast] != 0){
               swap(nums[slow],nums[fast]);
               slow++;
           }
       }
    }
};
*/
/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(int fast = 0;fast < nums.size();fast++){
            if(nums[fast] != val){
                swap(nums[slow],nums[fast]);
                slow++;
            }
        }
        return slow;
    }
};
*/
/*
去重
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        for(int fast = 1;fast < nums.size();fast++){
            if(nums[fast] != nums[slow]){
                slow++;
                swap(nums[slow],nums[fast]);
            }
        }
        return slow + 1;
    }
};
*/
/*
19. 删除链表的倒数第 N 个结点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* vhead = new ListNode(0,head);
        ListNode* slow = vhead;
        ListNode* fast = vhead;
        for(int i = 0;i < n;i++){
            fast = fast->next;
        }
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* delnode = slow->next;
        slow->next = slow->next->next;
        delete delnode;
        return vhead->next;
    }
};
*/