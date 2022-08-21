#include <iostream>
using namespace std;

int N;
int list[50];

int main() {
    /** INPUT **/
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }
    /** SOLUTION **/
    int a, b;
    if (N <= 2) {
        if (N == 1) {
            // 값이 여러개임. A
            cout << 'A';
        }
        else {
            if (list[0] == list[1]) {
                // a가 1이고, b가 0인 것.
                cout << list[0];
            }
            else {
                // 값이 여러개임. A.
                cout << 'A';
            }
        }
        return 0;
    }
    else {
        int inter1 = list[1] - list[0];
        int inter2 = list[2] - list[1];
        if (inter1 == 0) {
            a = 0;
        }
        else {
            if (inter2 % inter1 != 0) {
                cout << 'B';
                return 0;
            }
            a = inter2 / inter1;
        }
        b = list[1] - a*list[0];
    }

    for (int idx = 1; idx < N; idx++) {
        if (list[idx] != list[idx-1]*a + b) {
            cout << 'B';
            return 0;
        }
    }

    cout << list[N-1]*a + b;
    return 0;
}