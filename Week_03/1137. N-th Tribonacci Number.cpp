/**
 * 时间复杂度为O(n)
 * 跟斐波那契差不多，斐波那契是前两个数相加，这里是前三个数相加
 **/
class Solution {
public:
    int tribonacci(int n) {
        vector<int> vec(n + 1, 0);

        vec[0] = 0;
        if (n >= 1)
            vec[1] = 1;
        if (n >= 2)
          vec[2] = 1;

        for (int i = 3; i < n + 1; i++) {
            vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
        }
        return vec[n];
    }
};