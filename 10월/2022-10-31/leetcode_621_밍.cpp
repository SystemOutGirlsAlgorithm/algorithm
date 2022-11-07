class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        vector<int> v(26,0);
        int maxnum = 0;
        
        for (auto c: tasks) {
            v[c - 'A']++;
            maxnum = max(maxnum, v[c - 'A']);
        }
            
        int ans = (maxnum - 1) * (n + 1);
        for (auto i: v) if(i == maxnum) ans++;
        
        return max((int)tasks.size(), ans);
    }
};