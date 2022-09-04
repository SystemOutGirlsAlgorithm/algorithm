#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> pre_order;

void find_(int start, int end) {
    if (start >= end) return ;
    if (start == end-1) {
        cout << pre_order[start] << "\n";
        return ;
    }

    int root_num = pre_order[start];
    int idx = start;

    while (idx < end && root_num > pre_order[++idx]);

    find_(start+1, idx);
    find_(idx, end);

    cout << pre_order[start] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int temp;
    while (cin >> temp) {
        pre_order.push_back(temp);
    }

    find_(0, pre_order.size());

    return 0;
}