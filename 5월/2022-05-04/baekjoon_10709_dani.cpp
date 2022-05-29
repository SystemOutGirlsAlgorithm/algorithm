#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

int main() 
{
    int h, w, count;
    bool flag;
    string temp;
    vvi ans;
    cin >> h >> w;
    ans.assign(h, vector<int>(w, -1));

    for (int i=0; i<h; i++) {
        cin >> temp;

        flag = false;
        count = 0;

        for (int j=0; j<w; j++) {
            if (temp[j] =='c') {
                ans[i][j] = 0;
                flag = true;
                count = 0;
            }
            else if (flag == true) {
                count+=1;
                ans[i][j] = count;
            }
        }
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}