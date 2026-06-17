//链表 206 203 21 2 24
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while(cur != nullptr){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
*/
/*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* vhead = new ListNode(0,head);
        ListNode* pre = vhead;
        ListNode* cur = head;
        while(cur != nullptr){
            if(cur->val == val){
                pre->next = cur->next;
                ListNode* temp = cur;
                cur = cur->next;
                delete temp;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return vhead->next;
    }
};
*/
/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode();
        ListNode* cur = result;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        while(cur1 != nullptr && cur2 != nullptr){
            if(cur1->val > cur2->val){
                cur->next =cur2;
                cur = cur->next;
                cur2 = cur2->next;
            }else{
                cur->next = cur1;
                cur = cur->next;
                cur1 = cur1->next;
            }
        }
        if(cur1 != nullptr){
            cur->next = cur1;
        }
        if(cur2 != nullptr){
            cur->next = cur2;
        }
        return result->next;
    }
};
*/
/*
*/
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result;
        ListNode* cur = &result;
        int carry = 0;
        while(l1 || l2 || carry){
            if(l1){
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2){
                carry += l2->val;
                l2 = l2->next;
            }
            cur = cur->next = new ListNode(carry%10);
            carry /= 10;
        }
        return result.next;
    }
};
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* vhead = new ListNode(0,head);
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* pre = vhead;
        ListNode* odd = head;
        ListNode* even = head->next;
        while(odd != nullptr && even != nullptr){
            pre->next = even;
            odd->next = even->next;
            even->next = odd;
            pre = odd;
            odd = odd->next;
            even = odd ? odd->next : nullptr;
        }
        return vhead->next;
    }
};  


