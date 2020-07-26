class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while(i >= 0) {
            p[i]++;
            if (p[i] > n) {
                i--;
            }
            else if (i == k - 1) {
                result.push_back(p);
            }
            else {
                i++;
                p[i] = p[i - 1];
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vec;
        vector<int> nums;
        
        recursion(n, k, {}, vec);
        return vec;
    }
    
    void recursion(int n, int k, vector<int> nums, vector<vector<int>> &vec) {
        if (k <= 0) {
            vec.push_back(nums);
            return ;
        }
        if (n - 1 < 0) {
            return ;
        }
        recursion(n - 1, k, nums, vec);
        nums.push_back(n);
        recursion(n - 1, k - 1, nums, vec);
    }
};