#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int num;
vector<int> seq;

int main() {
    cin >> N;
    cin >> num;
    seq.push_back(num);

    vector<int>::iterator idx;
    while (--N) {
        cin >> num;
        if (seq.back() < num) {
            seq.push_back(num);
        }
        else {
            idx = lower_bound(seq.begin(), seq.end(), num);
            *idx = num;
        }
    }

    cout << seq.size();
    return 0;
}