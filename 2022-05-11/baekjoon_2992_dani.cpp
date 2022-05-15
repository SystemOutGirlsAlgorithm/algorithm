#include <iostream>
#include <vector>
#include <string>

using namespace std;

void func(string x, int &min, int pos, int length, vector<string> &ans, vector<bool> &check) 
{
    string temp_s;
    int target, num;
    
    if (pos == length) {
        for (int i=0; i<length; i++) {
            temp_s += ans[i];
        }
        target = stoi(x);
        num = stoi(temp_s);

        if (target < num) {
            if (min > num) {
                min = num;
            }

            return;
        }
    }

    for (int i=0; i<length; i++) {
        if (!check[i]) {
            check[i] = true;
            ans[pos] = x[i];
            func(x, min, pos+1, length, ans, check);
            check[i] = false;
            ans[pos] = "0";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string x;
    int min = 10e8;
    int length;
    cin >> x;

    length = x.size();
    vector<string> ans(length);
    vector<bool> check(length,false);
    
    func(x, min, 0, length, ans, check);
    if (min == 10e8) cout << "0" << "\n";
    else cout << min << "\n";
    return 0;
}