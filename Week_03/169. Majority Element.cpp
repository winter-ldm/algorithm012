class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mymap;
        int max = 0;
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            mymap[nums[i]]++;
        }
        for (auto m : mymap) {
            if (max < m.second) {
                max = m.second;
                result = m.first;
            }
        }
        return result;
    }
};