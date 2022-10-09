class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)
            return n;
        
        vector<int> v(n);
        int num = 2;
        v[0] = 1;
        v[1] = 2;
        while (num < n) {
            v[num] = v[num - 1] + v[num - 2];
            num++;
        }
        return v[n - 1];
    }
};