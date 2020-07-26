/**
 * 二叉搜索树中序遍历的时候是升序排列，所以中序遍历后判断数据是否是升序排列即可
 **/
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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<int> mystack;
        recursion(root, mystack);
        
        if (mystack.size() == 0)
            return true;
        int top = mystack.top();
        mystack.pop();
        while (mystack.size()) {
            if (mystack.top() >= top) {
                return false;
            }
            top = mystack.top();
            mystack.pop();
        }
        return true;
    }
    void recursion(TreeNode* root, stack<int> &mystack) {
        if (root == NULL)
            return ;
        recursion(root->left, mystack);
        mystack.push(root->val);
        recursion(root->right, mystack);
    }
};