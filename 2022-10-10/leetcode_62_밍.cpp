class Solution {
public:
    int uniquePaths(int m, int n) {
        double num = m + n - 2, nnum = min(m, n) - 1, res = 1;
        for (double i = nnum; i > 0; i--, num--) {
            res *= (num / i);
        }
        return (int)(res + 0.001);
    }
};