class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int ptr1 = 0, ptr2 = 1, len = 1;
        map<char, int> m;
        m[s[ptr1]]++;
        while (ptr2 < s.size()) {
            m[s[ptr2]]++;
            if (m[s[ptr2]] > 1) 
                while(m[s[ptr2]] > 1) m[s[ptr1++]]--;
            ptr2++;
            
            if (len < ptr2 - ptr1) len = ptr2 - ptr1;
        }
        return len;
    }
};