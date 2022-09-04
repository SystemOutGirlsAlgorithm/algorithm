#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans = 0;
vector<long long> arr;

int main() {
    cin >> N;
    long long temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    for (int idx = 0; idx < N; idx++) {
        int left = 0;
        int right = N-1;
        while (left < right) {
            long long sum = arr[left]+arr[right];
            if (sum==arr[idx]) {
                if (left != idx && right != idx) {
                    ans++;
                    break;
                }
                else if (left == idx) left++;
                else if (right == idx) right--;
            }
            else if (sum>arr[idx]) right--;
            else left++;
        }
    }

    cout << ans;

    return 0;
}