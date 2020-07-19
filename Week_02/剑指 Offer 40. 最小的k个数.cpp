/**
 * 时间复杂度为O(nlogn)
 * 用sort将arr升序排列，然后取前k位即是所求
 **/

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec;

        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; i++) {
            vec.push_back(arr[i]);
        }
        return vec;
    }
};