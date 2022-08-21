#include <iostream>
using namespace std;

long long minn, maxx;
int isNini[1000001];
int cnt = 0;

int main() {
    cin >> minn >> maxx;

    int count = maxx-minn+1;

    for (int i = 0; i < count; i++) {
        isNini[i] = 1;
    }

    long long ii, mm;
    for (long long i = 2; i*i <= maxx; i++) {
        // (1) ---------------------------------------
        ii = i*i;
        if (minn%ii == 0) mm = minn;
        else mm = (minn/ii+1)*ii;

        for (long long j = mm; j <= maxx; j += ii) {
            isNini[j-minn] = 0;
        }
        // (2) ---------------------------------------
        // ii = i*i;
        // long long n = minn / ii;
        // if (minn%ii) n++;
        // while (n*ii<=maxx) {
        //     isNini[n*ii-minn] = 0;
        //     n++;
        // }
    }

    for (int i = 0; i < count; i++) {
        if (isNini[i])
            ++cnt;
    }

    cout << cnt;

    return 0;
}