#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 4000000

int N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    bool isNotPrime[MAX+1];
    isNotPrime[1] = true;
    
    for (int i = 2; i*i <= MAX; ++i) {
        if (!isNotPrime[i]) {
            for (int j = i*i; j <= MAX; j += i) {
                isNotPrime[j] = true;
            }
        }
    }

    vector<int> primesum;
    primesum.push_back(0);
    int sum = 0;
    for (int i = 2; i <= MAX; ++i) {
        if (!isNotPrime[i]) {
            sum += i;
            primesum.push_back(sum);
        }
    }

    int ans = 0;
    int left_idx = 0;
    int right_idx = 0;

    
    while (left_idx <= right_idx && right_idx < primesum.size()) {
        if (primesum[right_idx] - primesum[left_idx] > N) ++left_idx;
        else if (primesum[right_idx] - primesum[left_idx] < N) ++right_idx;
        else {
            ++ans;
            ++right_idx;
        }
    }

    cout << ans;
    
    return 0;
}