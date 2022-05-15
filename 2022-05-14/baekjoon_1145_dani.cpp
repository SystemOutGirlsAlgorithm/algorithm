#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans, count, min = 101, num=1;
    vector<int> arr(5);
    for (int i=0; i<5; i++) {
        cin >> arr[i];
    }

    while (1) {
        count = 0;

        for (int i=0; i<5; i++) {
            if (num % arr[i] == 0 && num >= arr[i]) count++;
        }
        if (count >= 3) {
            cout << num << "\n";
            break;
        }
        num++;
    }
    return 0;
}