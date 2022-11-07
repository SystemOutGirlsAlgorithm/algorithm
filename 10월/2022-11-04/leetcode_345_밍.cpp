class Solution {
public:
    string reverseVowels(string s) {
        stack<char> sc;
        queue<int> q;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                sc.push(s[i]);
                q.push(i);
            }
        }
                
        int index;
        while (!q.empty()) {
            index = q.front();
            q.pop();
            
            s[index] = sc.top();
            sc.pop();
        }
        
        return s;
    }
};