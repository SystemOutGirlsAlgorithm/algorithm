#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, ans = 987654321;
int arr[100000];

int main() {
    cin >> N >> S;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int left = 0;
    int right = 1;
    int sum = arr[left];
    while (left < right && right <= N) {
        if (sum >= S) {
            //printf(" %d ~ %d : %d\n", left, right-1, sum);
            ans = min(ans, right-left);
            sum -= arr[left];
            left++;
        }
        else if (right != N) {
            sum += arr[right];
            right++;
        }
        else break;
    }

    if (ans != 987654321) cout << ans;
    else cout << 0;
}