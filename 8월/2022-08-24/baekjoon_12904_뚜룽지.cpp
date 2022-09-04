#include <iostream>
#include <string>
using namespace std;

string S, T;
int ans = 0;

int main() {
    cin >> S >> T;

    int s_leng = S.length();
    int t_leng = T.length();
    for (int j = 0; j < t_leng-s_leng; j++) {
        if (T[T.length()-1] == 'B') { // 뒤집고 B를 추가한 경우.
            T.erase(--T.end());

            string T_temp = T;
            for (int i = 0; i < T_temp.length(); i++) {
                T_temp[i] = T[T.length()-1-i];
            }
            T = T_temp;
        }
        else { // A를 추가한 경우.
            T.erase(--T.end());
        }
    }

    if (T.compare(S) == 0) {
        ans = 1;
    }


    cout << ans;
    return 0;
}