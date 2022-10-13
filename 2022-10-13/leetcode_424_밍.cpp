class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int res = 0, left = 0, right = 0, maxcnt = 0;
        for (; right < s.size(); right++) {
            maxcnt = max(maxcnt, ++cnt[s[right] - 'A']);
            if (right - left + 1 - maxcnt > k) 
                cnt[s[left++] - 'A']--;
        }
        return s.size() - left;
    }
};