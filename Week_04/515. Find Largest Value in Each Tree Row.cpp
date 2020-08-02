/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<priority_queue<int>> vec;
        vector<int> result;

        //将每一行的数据存入vector<vector<int>>
        recursion(root, 0, vec);
        //取出优先队列的队头即为最大值
        for (auto pq : vec) {
            result.push_back(pq.top());
        }
        return result;
    }
    void recursion(TreeNode* root, int level, vector<priority_queue<int>> &vec) {
        if (root == NULL) {
            return ;
        }
        if (vec.size() == level) {
            vec.push_back(priority_queue<int>());
        }
        vec[level].push(root->val);
        recursion(root->left, level + 1, vec);
        recursion(root->right, level + 1, vec);
    }
};

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> vec;
        
        recursion(root, 0, vec);
        return vec;        
    }
    void recursion(TreeNode* root, int level, vector<int> &vec) {
        if (root == NULL) {
            return ;
        }
        if (vec.size() == level) {
            vec.push_back(root->val);
        }
        else if (vec[level] < root->val) {
            vec[level] = root->val;
        }
        
        recursion(root->left, level + 1, vec);
        recursion(root->right, level + 1, vec);
    }
};