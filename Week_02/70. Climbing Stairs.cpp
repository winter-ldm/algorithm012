/**
 * 可以用简单递归来解决，但是时间复杂度太高2的n次方
 * 爬楼梯就是斐波那契问题，用数组将每爬一级楼梯的方法数存起来即可，时间复杂度为O(n)
 **/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec(n, 0);
        int i = 0;
        
        vec[0] = 1;
        if (n > 1) vec[1] = 2;
        for (i = 2; i < n; i++) {
            vec[i] = vec[i - 1] + vec[i - 2];
        }
        return vec[n - 1];
    }
};

/**
 * 优化递归 时间复杂度为O(n)
 * 用一个数组将已经计算过的楼梯层数保存起来，那么就不会有重复计算了
 **/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec(n, 0);
        return recursion(n - 1, vec);
    }
    int recursion(int n, vector<int> &vec) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 2;
        }
        
        if (vec[n] > 0) {
            return vec[n];
        }
        vec[n] = recursion(n - 1, vec) +  recursion(n - 2, vec);
        return vec[n];
    }
};