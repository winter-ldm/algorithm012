/*283. 移动零*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != j)
                    nums[j] = nums[i], nums[i] = 0;
                j++;
            }
        }
    }
};
/*1. Two Sum*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int cha = target - nums[i];
            if(mMap.find(cha) != mMap.end())
                return {mMap[cha], i};
            mMap[nums[i]] = i;
        }
        return {};
    }
};
    