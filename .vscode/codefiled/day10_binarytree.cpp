// 二叉树的遍历 前序144 中序94 后序145 层序102
//  #include <algorithm>
//  #include <vector>
//  #include <unordered_map>
//  #include <cctype>
//  #include <cmath>
//  #include <deque>
//  #include <unordered_set>
//  #include <stack>
//  #include <queue>
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 前序
/*
//栈实现
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret;
        if(root != nullptr){
            stk.push(root);
        }
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            ret.push_back(node->val);
            if(node->right != nullptr){
                stk.push(node->right);
            }
            if(node->left != nullptr){
                stk.push(node->left);
            }
        }
        return ret;
    }
};
//递归实现,好慢
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root != nullptr){
            ret.push_back(root->val);
            vector<int> left = preorderTraversal(root->left);
            vector<int> right = preorderTraversal(root->right);
            ret.insert(ret.end(),left.begin(),left.end());
            ret.insert(ret.end(),right.begin(),right.end());
        }
        return ret;
    }
};
*/
/*
//中序 栈
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur != nullptr || !stk.empty()){
            if(cur != nullptr){
                stk.push(cur);
                cur = cur->left;
            }else{
                TreeNode* node = stk.top();
                stk.pop();
                ret.push_back(node->val);
                cur = node->right;
            }
        }
        return ret;
    }
};
//中序递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root != nullptr){
            vector<int> left = inorderTraversal(root->left);
            ret.insert(ret.end(),left.begin(),left.end());
            ret.push_back(root->val);
            vector<int> right = inorderTraversal(root->right);
            ret.insert(ret.end(),right.begin(),right.end());
        }
        return ret;
    }
};
*/
// 后序
/*
//递归
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root != nullptr){
            vector<int> left = postorderTraversal(root->left);
            ret.insert(ret.end(),left.begin(),left.end());
            vector<int> right = postorderTraversal(root->right);
            ret.insert(ret.end(),right.begin(),right.end());
            ret.push_back(root->val);
        }
        return ret;
    }
};
//栈实现
//头 右 左 反转
//左 右 头
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        if(root != nullptr){
            stk.push(root);
        }
        TreeNode* cur = root;
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            ret.push_back(node->val);
            if(node->left != nullptr){
                stk.push(node->left);
            }
            if(node->right != nullptr){
                stk.push(node->right);
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            //如果右子树不存在或者右子树已经访问过了，那么就可以访问当前节点了
            if(root->right == nullptr || root->right == prev){
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            }
            else{
                stk.push(root);
                root = root->right;
            }
        }
        return res;
    }
};
*/
/*
//层序，队列
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> que;
        if(root != nullptr){
            que.push(root);
        }
        while(!que.empty()){
            int size = que.size();
            vector<int>level;
            for(int i = 0;i < size;i++){
                TreeNode* node = que.front();
                que.pop();
                level.push_back(node->val);
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
            ret.push_back(level);
        }
        return ret;
    }
};
*/








