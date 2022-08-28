#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<long long> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // A, B
    vector<long long> ab;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(A[i]+B[j]);
            //printf("%d ", A[i]+B[j]);
        }
    }
    //printf("\n AB ----- CD \n");
    // B, C
    vector<long long> cd;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cd.push_back(C[i]+D[j]);
            //printf("%d ", C[i]+D[j]);
        }
    }
    //printf("\n-------------\n");
    long long ans = 0;
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    for (int i = 0; i < ab.size(); i++) {
        ans += (upper_bound(cd.begin(), cd.end(), -ab[i]) - (lower_bound(cd.begin(), cd.end(), -ab[i])));
    }
    cout << ans;
    return 0;
}