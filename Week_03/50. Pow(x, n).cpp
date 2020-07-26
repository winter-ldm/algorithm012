class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
    
    double pow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double sum = pow(x, n / 2);
        if (n % 2 == 0) {
            return sum * sum;
        }
        else {
            return n < 0 ? 1 / x * sum * sum : x * sum * sum;
        }
    }
};
