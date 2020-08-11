/**
 * 从能走的范围里面选出一次能跨过过大的步数，然后又从该位置找出能跨过的最大步数，当前面跨过的步数+当前的最大步数能跨到最后一个位置即为所求
 **/
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, start = 0, end = 0, flag = 0, n = nums.size() - 1;

        while (end < n) {
            step++;
            int endflag = end + 1;
            for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n) {
                    return step;
                }
                endflag = max(endflag, i + nums[i]);
            }
            start = end + 1;
            end = endflag;
        }
        return step;
    }
};