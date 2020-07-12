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