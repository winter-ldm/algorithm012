/**
 * 时间复杂度为O(n)
 * 数组是升序的，当发现数组中的数据大于target时即可判断该数组不存在等于target的数并且该位置即为target要插入的位置
 **/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                return i;
            else if (nums[i] > target)
                return i;
        }
        return nums.size();
    }
};

/**
 * 最优解
 * 用二分查找，时间复杂度是O(logn)
 **/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pre = 0, tail = nums.size() - 1, mid = 0;
        
        while (pre <= tail) {
            mid = pre + (tail - pre) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                pre = mid + 1;
            }
            else {
                tail = mid - 1;
            }
        }
        return pre;
    }
};