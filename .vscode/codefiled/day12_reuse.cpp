//递归509 226 101 105 106
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};
/*
//斐波那契数列
class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        return fib(n-1) + fib(n-2);
    }
};
//优化，数组存储
class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
//优化，滚动数组,只需要前两个数
class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int dp[2] = {0,1};
        for(int i = 2;i <= n;i++){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
*/
/*
//翻转二叉树
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* rigtht = invertTree(root->right);
        root->left = rigtht;
        root->right = left;
        return root;
    }
};
*/
/*
//对称二叉树
class Solution {
private:
    bool isSymmetricHelper(TreeNode* left,TreeNode* right){
        if(left == nullptr && right == nullptr)return true;
        if(left == nullptr || right == nullptr)return false;
        if(left->val != right->val)return false;
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return isSymmetricHelper(root->left, root->right);
    }
};
//从前序和中序遍历构造二叉树
class Solution {
private:
    unordered_map<int,int> index;
public:
    TreeNode* buildHelper(vector<int>& preorder,vector<int>& inorder,int preorder_left,int preorder_right,int inorder_left,int inorder_right){
        if(preorder_left > preorder_right || inorder_left > inorder_right){
            return nullptr;
        }
        int preorder_root = preorder_left;//前序遍历的第一个节点是根节点
        int inorder_root = index[preorder[preorder_root]];//根节点在中序遍历中的位置
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int left_size = inorder_root - inorder_left;//左子树的节点数
        root->left = buildHelper(preorder,inorder,preorder_left + 1,preorder_left + left_size,inorder_left,inorder_root - 1);
        root->right = buildHelper(preorder,inorder,preorder_left + left_size + 1,preorder_right,inorder_root + 1,inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        //哈希表，存储中序遍历中每个节点的索引，方便快速查找根节点在中序遍历中的位置
        for(int i = 0;i < n;i++){
            index[inorder[i]] = i;
        }
        return buildHelper(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
*/
/*
class Solution {
private:
    unordered_map<int,int> index;
    TreeNode* buildHelper(vector<int>& inorder,vector<int>& postorder,int inorder_left,int inorder_right,int postorder_left,int postorder_right){
        if(inorder_left > inorder_right) return nullptr;
        int postorder_root = postorder_right;
        int inorder_root = index[postorder[postorder_root]];
        TreeNode* root = new TreeNode(postorder[postorder_root]);
        int left_size = inorder_root - inorder_left;
        int right_size = inorder_right - inorder_root;
        root->left = buildHelper(inorder,postorder,inorder_left,inorder_left+left_size - 1,postorder_left,postorder_left + left_size - 1);
        root->right = buildHelper(inorder,postorder,inorder_root + 1,inorder_right,postorder_left + left_size,postorder_right - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0;i < inorder.size();i++){
            index[inorder[i]] = i;
        }
        return buildHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
*/









