#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;

int main() {
    /* INPUT */
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    
    queue<int> table;
    for (int i = 1; i <= N; ++i) {
        table.push(i);
    }

    vector<int> ans;
    /* SOLUTION */
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < K; ++j) {
            table.push(table.front());
            table.pop();
        }
        ans.push_back(table.front());
        table.pop();
    }

    /* OUTPUT */
    vector<int>::iterator iter = ans.begin();
    cout << "<" << *iter;
    iter++;
    for ( ; iter != ans.end(); iter++){
        cout << ", " << *iter;
    }
    cout << ">" << endl;

    return 0;
}