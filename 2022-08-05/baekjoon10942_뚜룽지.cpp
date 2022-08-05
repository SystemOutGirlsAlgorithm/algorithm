#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int s, e;
int number[2001];
int check_pr[2001][2001];

int isSame(int idx1, int idx2) {
    return number[idx1] == number[idx2];
}

int Check_pr(int s, int e) {
    if (check_pr[s][e] != -1) {
        return check_pr[s][e];
    }
    if (e-s < 2) {
        return check_pr[s][e] = isSame(s, e);
    }
    return check_pr[s][e] = isSame(s, e) & Check_pr(s+1, e-1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    fill(&check_pr[0][0], &check_pr[0][0]+4004001, -1);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> number[i];
        check_pr[i][i] = 1;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        cout << Check_pr(s, e) << "\n";
    }
}