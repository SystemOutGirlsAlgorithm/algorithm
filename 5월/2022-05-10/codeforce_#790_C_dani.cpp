#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, m, n, count=0, min = 2147483647; //길이가 m인 n개의 수
    string word1, word2;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        count = 0; min = 2147483647;
        vector <string> word(n);
        for (int i=0; i<n; i++) {
            cin >> word[i];
        }

        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                word1 = word[i];
                word2 = word[j];
                for (int k=0; k<m; k++) {
                    count += abs((int)word1[k]-(int)word2[k]);
                }

                if (min > count) min = count;
                count = 0;
            }
        }
        cout << min << "\n";
        word.clear();
    }

    return 0;
}