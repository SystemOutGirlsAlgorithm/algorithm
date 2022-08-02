#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N;
long long info[5000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> info[i];
    }
    sort(info, info+N);

    long long sum_solution = LLONG_MAX;
    long long ans_l, ans_m, ans_r;

    for (int i = 0; i < N-2; i++) {
        long long left_v = info[i];
        int middle = i+1;
        int right = N-1;
        while (middle < right) {
            long long sum_temp = left_v + info[middle] + info[right];
            if (abs(sum_temp) < sum_solution) {
                ans_l = left_v;
                ans_m = info[middle];
                ans_r = info[right];
                sum_solution = abs(sum_temp);
            }

            if (sum_temp > 0) right--;
            else if (sum_temp < 0) middle++;
            else {
                i = N-2;
                break;
            }
        }
    }

    cout << ans_l << " " << ans_m << " " << ans_r;
}