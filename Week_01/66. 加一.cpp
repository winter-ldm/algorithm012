/**
 * 空间复杂度O(1)
 * 时间复杂度O(n)
 * 像做数学题一样考虑所有情况即可，正常无进位最末位+1后即可返回，有进位的时候缺少最高位位置需要在第一位前插入进位，
 **/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0, i = 0;
        int iFlag = 0;

        if (digits[0] != 0)
            iFlag = 1;
        digits[digits.size() - 1] += 1;
        sum = digits[digits.size() - 1];
        if ((sum /= 10) == 0 )
            return digits;
        digits[digits.size() - 1] = 0;
        for (i = digits.size() - 2; i >= 0; i--) {
            digits[i] += sum;
            sum = digits[i];
            digits[i] %= 10;
            if ((sum /= 10) == 0 )
             break;
        }
        if (iFlag == 1 && sum == 1)
            digits.insert(digits.begin(), sum);
        return digits; 
    }
};
/**
 * 最优解
 * 空间复杂度O(1)
 * 时间复杂度O(n)
 * 如果所有位数都是9的话，每一位都变成0后将第一位置为1，最后插入一位0
 * 当遇到数据不是9时+1即可返回
 **/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }
		digits[0] =1;
		digits.push_back(0);
        return digits; 
    }
};