// 二叉树进阶104 98 112 108 109 662 199
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
我的天哪，递归大人
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right) + 1;
    }
};
//层序遍历,最大深度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i < size;i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
*/
/*
//验证二叉搜索树
class Solution {
private:
    TreeNode* SearchRightNode(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* rightNode = SearchRightNode(root->right);
        return rightNode == nullptr ? root : rightNode;
    }
    TreeNode* SearchLeftNode(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* leftNode = SearchLeftNode(root->left);
        return leftNode == nullptr ? root : leftNode;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        if(isValidBST(root->left) && isValidBST(root->right)){
            if(root->left != nullptr && SearchRightNode(root->left)->val >= root->val){
                return false;
            }
            if(root->right != nullptr && SearchLeftNode(root->right)->val <= root->val){
                return false;
            }
            return true;
        }
        return false;
    }
};
//递归中序遍历，前一个节点的值必须小于当前节点的值
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while(root != nullptr || !stk.empty()){
            if(root != nullptr){
                stk.push(root);
                root = root->left;
            }else{
                root = stk.top();
                stk.pop();
                if(prev != nullptr && prev->val >= root->val){
                    return false;
                }
                prev = root;
                root = root->right;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        bool isValid = true;
        function<void(TreeNode*)> dfs = [&](TreeNode* node){
            if(node == nullptr){
                return;
            }
            dfs(node->left);
            if(prev != nullptr && prev->val >= node->val){
                isValid = false;
                return;
            }
            prev = node;
            dfs(node->right);
        };
        dfs(root);
        return isValid;
    }
};
*/
/*
//路径总和
*/
class Solution
{
private:
    bool hasPathSumHelper(TreeNode *root, int targetSum, int &sum)
    {
        if (root == nullptr)
        {
            return false;
        }
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (sum == targetSum)
            {
                return true;
            }
        }
        if (hasPathSumHelper(root->left, targetSum, sum))
        {
            return true;
        }
        if (hasPathSumHelper(root->right, targetSum, sum))
        {
            return true;
        }
        sum -= root->val;
        return false;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        return hasPathSumHelper(root, targetSum, sum);
    }
};
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        // 回溯法
        function<bool(TreeNode *)> dfs = [&](TreeNode *node)
        {
            if (node == nullptr)
            {
                return false;
            }
            sum += node->val;
            if (node->left == nullptr && node->right == nullptr)
            {
                if (sum == targetSum)
                {
                    return true;
                } // 加到叶节点等于目标值，true
            }
            if (dfs(node->left))
            {
                return true;
            }
            if (dfs(node->right))
            {
                return true;
            }
            sum -= node->val; // 回退
            return false;
        };
        return dfs(root);
    }
};
/*
//有序数组转换为二叉搜索树
class Solution {
private:
    TreeNode* chooseNode(vector<int>& nums,int left,int right){
        if(left > right){
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = chooseNode(nums, left, mid - 1);
        node->right = chooseNode(nums, mid + 1, right);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return chooseNode(nums, 0, nums.size() - 1);
    }
};
*/
/*
//有序链表转换为二叉搜索树
class Solution {
private:
//快慢指针找到链表的中点,偏右
    ListNode* findMiddle(ListNode* left,ListNode* right){
        ListNode* slow = left;
        ListNode* fast = left;
        while(fast != right && fast->next != right){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    TreeNode* buildTree(ListNode* left,ListNode* right){
        if(left == right){
            return nullptr;
        }
        ListNode* mid = findMiddle(left, right);
        TreeNode* node = new TreeNode(mid->val);
        node->left = buildTree(left, mid);//左闭右开
        node->right = buildTree(mid->next, right);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* tail = nullptr;
        return buildTree(head, tail);//左闭右开,tail为nullptr表示链表的末尾
    }
};
*/
/*
//二叉树最大宽度
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        queue<pair<TreeNode*,unsigned long long>> que;
        if(root != nullptr){
            que.push({root,0});
        }
        int depth = 0;
        while(!que.empty()){
            int size = que.size();
            unsigned long long left = que.front().second;
            unsigned long long right = que.back().second;
            maxWidth = max(maxWidth, (int)(right - left + 1));
            for(int i = 0;i < size;i++){
                auto [node,index] = que.front();
                que.pop();
                //满二叉树且根节点的索引为0
                //索引太大，需要减去当前层最左边节点的索引，避免整数溢出
                index = index - left;
                //左子节点的索引为2 * index + 1，右子节点的索引为2 * index + 2
                if(node->left != nullptr){
                    que.push({node->left,index * 2 + 1});
                }
                if(node->right != nullptr){
                    que.push({node->right,index * 2 + 2});
                }
            }
            depth++;
        }
        return maxWidth;
    }
};
*/
// 二叉树的右视图
// 一层一个节点，最后一个节点
/*
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ret;
        queue<TreeNode *> que;
        if (root != nullptr)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (i == size - 1)
                {
                    ret.push_back(node->val);
                }
                if (node->left != nullptr)
                {
                    que.push(node->left);
                }
                if (node->right != nullptr)
                {
                    que.push(node->right);
                }
            }
        }
        return ret;
    }
};
*/
