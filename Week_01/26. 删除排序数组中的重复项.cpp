/**
 * 没有额外申请空间，空间复杂度O(1)
 * 数组的每个元素只遍历一次，时间复杂度为O(n)
 * 需要一个变量iFlag标记数组存到哪个位置了
 * 当找到与nums[i]不同的元素nums[j]时，将nums[j]存放在nums[iFalg]位置，然后将i赋值为j进行下一轮循环
 **/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int iNum = 1;
        int j = 0;

        for (int i = 0; i < nums.size() - 1; i = j){
            int iTem = nums[i];
            for (j = i + 1; j < nums.size();) {
                if (nums[j] == iTem) {
                    j++;
                }
                else {
                    nums[iNum++] = nums[j];
                    break;
                }
            }
        }
        return iNum;
    }
};