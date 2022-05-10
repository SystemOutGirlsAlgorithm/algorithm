#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp, left, right, sum, min = 2*10e8;
    vector<int> arr;
    vector<int> ans(2);
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> temp;
        arr.emplace_back(temp);
    }
    sort (arr.begin(), arr.end());

    left = 0; right = n-1;

    while (left < right) {
        sum = arr[left] + arr[right];

        if (abs(sum) <= min) {
            min = abs(sum);
            ans[0] = arr[left];
            ans[1] = arr[right];
        }

        if (abs(sum) == 0) {
            break;
        }
        if (sum < 0) {
            left++;
        }
        else if (sum > 0) {
            right--;
        }
    }

    cout << ans[0] << ' ' << ans[1] << "\n";
    return 0;
}