class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        map<char, int> m;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                guess[i] = 'a';
                a++;
            } else {
                m[secret[i]]++;
            }
        }
        
        for (auto i: guess) {
            if (isalpha(i))
                continue;
            
            if (m[i] > 0) {
                m[i]--;
                b++;
            }
        }
        
        return to_string(a) + "A" + to_string(b) + "B";
    }
};