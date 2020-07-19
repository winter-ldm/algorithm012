/**
 *     1
 *   2   3
 *  4  	6 7 
 * 第一个inorder递归下去首先会找到左子树的左叶子节点4，然后将该左叶子节点4的数据存储下来，接着递归节点4的右子树继续找左叶子节点，这时候发现节点4没有右子树返回NULL
 * 回到节点2，保存结点2的数据，然后接着递归节点2的右子树，结点2无右子树，返回上一层NULL
 * 回到根节点1，保存结点1的数据，接着找节点1右子树的左叶子节点，为节点6，保存结点6数据，递归节点6的右子树，发现节点6无右子树返回NULL
 * 此时回到节点3，保存结点3数据，找节点3的右子树的左叶子节点，发现只有节点7左子树为空，返回到节点7并保存结点7的数据，节点7无右子树，到此遍历结束
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        
        inorder(root, vec);
        return vec;
    }
    
    void inorder(TreeNode* root, vector<int> &node) {
        if (root == NULL) 
            return ;
        
        inorder(root->left, node);
        node.push_back(root->val);
        inorder(root->right, node);
    }
};