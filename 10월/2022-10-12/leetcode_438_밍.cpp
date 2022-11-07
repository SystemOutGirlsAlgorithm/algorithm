class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, window(26, 0), pv(26, 0); // p_vector
        int left = 0, right = 0;
        
        if (s.size() < p.size())
            return res;
        
        while (right < p.size()) {
            window[s[right] - 'a']++;
            pv[p[right] - 'a']++;
            right++;
        };
        
        while (right < s.size()) {
            if (window == pv)
                res.push_back(left);
            
            window[s[right++] - 'a']++;
            window[s[left++] - 'a']--;
        };
        
        if (window == pv)
            res.push_back(left);
        return res;
    }
};