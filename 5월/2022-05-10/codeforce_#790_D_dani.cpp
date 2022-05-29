#include <iostream>
#include <vector>

using namespace std;
const int dx[4] = {1, 1, -1, -1};
const int dy[4] = {1, -1, 1, -1};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, max=0, chess, count;
    int a, b;
    vector <vector<int>> table;
    cin >> t;
    while (t--) {
        count = 0; max = 0;
        cin >> n >> m;
        table.assign(n, vector<int>(m));
        for (int i=0; i<n; i++) { //output ok
            for (int j=0; j<m; j++) {
                cin >> table[i][j];
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                count = 0;
                count += table[i][j];
                for (int k=0; k<4; k++) {
                    a=i; b=j;

                    if (a+dx[k] < 0 && b+dy[k] < 0) {
                        continue;
                    }
                    if (a+dx[k] >= n && b+dy[k] >= m) {
                        continue;
                    }

                    while (1) {
                        a = a + dx[k];
                        b = b + dy[k];
                        if (a>=0 && b>=0 && a<n && b<m){ 
                            count+=table[a][b];
                        }
                        else break;
                    }
                    if (max < count) max = count;
                }
            }
        }
        cout << max << "\n";
    }
    return 0;
}