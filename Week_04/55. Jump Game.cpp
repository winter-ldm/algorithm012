/**
 * 从后往前推，判断当前的可以走的步数是否可以走到下一步
 **/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int iFlag = nums.size() - 1;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] + i >= iFlag) {
                iFlag = i;
            }
        }
        return iFlag == 0;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int flag = 0;
        for (int i = 0; i < nums.size() && i <= flag; i++) {
            flag = max (flag, i + nums[i]);
        }
        return flag >= nums.size() - 1;
    }
};