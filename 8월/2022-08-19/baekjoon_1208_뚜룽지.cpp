#include <iostream>
#include <map>
using namespace std;

int arr[40];
int N, S;
long long ans = 0;
map<int, int> right_sum;

void subSumRight(int pivot, int sum) {
    if (pivot > N-1) {
        right_sum[sum]++;
        return ;
    }
    subSumRight(pivot+1, sum);
    subSumRight(pivot+1, sum+arr[pivot]);
}

void subSumLeft(int pivot, int sum) {
    if (pivot >= N/2) {
        ans += right_sum[S-sum];
        return ;
    }
    subSumLeft(pivot+1, sum);
    subSumLeft(pivot+1, sum+arr[pivot]);
}


int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    subSumRight(N/2, 0);
    subSumLeft(0, 0);

    if (S == 0) cout << ans-1;
    else cout << ans;

    return 0;
}