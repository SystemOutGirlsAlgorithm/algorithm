#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
int ans = 0;

void dfs(string s) {
    if (s.length() <= S.length()) {
        if (S.compare(s) == 0) ans = 1;
        return ;
    }
    
    if (s[s.length()-1] == 'A') { // 1. A를 추가 -> A가 뒷자리
        string s_temp = s;
        s_temp.erase(s_temp.end()-1);
        dfs(s_temp);
    }

    if (s[0] == 'B') { // 2. B를 추가하고 뒤집 -> B가 앞자리
        string s_temp = s;
        s_temp.erase(s_temp.begin());
        reverse(s_temp.begin(), s_temp.end());
        dfs(s_temp);
    }
}

int main() {
    cin >> S >> T;
    dfs(T);
    cout << ans;
    return 0;
}