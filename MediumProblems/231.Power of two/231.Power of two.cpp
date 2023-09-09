class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0)return false;
        double lhs = log(n);
        double rhs = log(2);
        double div = floor(lhs/rhs);
        if(pow(2,div) == n)return true;
        return false;
    }
};