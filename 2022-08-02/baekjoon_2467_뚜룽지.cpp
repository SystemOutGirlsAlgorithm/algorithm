#include <iostream>
#include <cmath>
using namespace std;

int N;
int info[100000];
int ans_l, ans_r;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> info[i];
    }

    int left = 0;
    int right = N-1;
    int sum_solution = abs(info[left] + info[right]);

    ans_l = info[left];
    ans_r = info[right];

    while (left<right) {
        int sum_temp = info[left] + info[right];
        if (abs(sum_temp) < sum_solution) {
            ans_l = info[left];
            ans_r = info[right];
            sum_solution = abs(sum_temp);
        }
        if (sum_temp < 0) left++;
        else right--;
    }

    cout << ans_l << " " << ans_r;
    return 0;
}