class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> num;
        
        recursion(nums, num, 0, vec);
        return vec;
    }
    void recursion(vector<int> nums, vector<int> num, int level, vector<vector<int>> &vec) {
        if (level >= nums.size()) {
            vec.push_back(num);
            return ;
        }
        
        recursion(nums, num, level + 1, vec);
        num.push_back(nums[level]);
        recursion(nums, num, level + 1, vec);
    }
};