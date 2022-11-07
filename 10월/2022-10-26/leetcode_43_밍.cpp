class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        vector<int> res(num1.size()+num2.size(), 0);
        int index, temp;
        
        for (int i = num2.size() - 1, m = 1; i>=0; i--, m++) {
            index = res.size() - m;
            for (int j = num1.size() - 1; j >= 0; j--) {
                temp = (num2[i] - '0') * (num1[j] - '0');
                if (temp >= 10) res[index - 1] += temp / 10;
                res[index] += temp % 10;
                index--;
            }
        }
        
        temp = 0;
        for (int i = res.size() - 1; i >= 0; i--) {
            if (temp) {
                res[i] += temp;    
            }
            
            if (res[i] >= 10) {
                temp = res[i] / 10;
                res[i] %= 10;
            }
            else temp = 0;
        }
        
        string ans = "";
        int i = 0;
        while (!res[i]) i++;
        
        while (i < res.size()) {
            ans += (res[i++] + '0');
        }
        
        return ans;
    }
};