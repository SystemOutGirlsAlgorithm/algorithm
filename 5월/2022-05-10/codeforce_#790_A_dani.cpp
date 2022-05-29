#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int t, sum=0, sum_back=0;
    string num;
    cin >> t;
    while (t--) {
        sum = 0; sum_back =0;
        cin >> num;
        for (int i=0; i<3; i++) {
            sum += (int)num[i] - '0';
        }
        for (int i=3; i<6; i++) {
            sum_back += (int)num[i] - '0';
        }
        if (sum == sum_back) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }   
    return 0;
}