class Solution {
public:
    int findMin(vector<int>& nums) {
        stack<int> mystack;

        if (nums.size() == 1){
            return nums[0];
        }
        mystack.push(nums[0]);
        for (int num : nums) {
            if (mystack.top() > num) {
                return num;
            }
            mystack.push(num);
        }
        return nums[0];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = 0;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            
            if (nums[low] <= nums[high]) {
                return nums[low];
            }
            else if (nums[mid] >= nums[low]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return -1;
    }
};