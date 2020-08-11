class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> vec;
        
        sort(nums.begin(), nums.end());
        recursion(nums, 0, vec);
        return vec;
    }
    void recursion(vector<int> nums, int begin, vector<vector<int>> &vec) {
        if (begin >= nums.size()) {
            vec.push_back(nums);
            return ;
        }
        for (int i = begin; i < nums.size(); i++) {
            if (i != begin && nums[begin] == nums[i]) {
                continue;
            }
            swap(nums[begin], nums[i]);
            recursion(nums, begin + 1, vec);
        }
    }
};