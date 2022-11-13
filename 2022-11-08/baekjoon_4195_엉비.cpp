#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define MAX 200000

int T, F, cnt;
map<string, int> dict;
int parent[MAX];
int root[MAX];

void init() {
    cnt = 0;
    for (int i = 0; i < 2*F; ++i) {
        parent[i] = i;
        root[i] = 1;
    }
    dict.clear();
}


int find(int a) {
    if (a != parent[a]) {
        return parent[a] = find(parent[a]);
    }
    else return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    string name1, name2;
    while(T--) {
        cin >> F;
        init();
        for (int i = 0; i < F; ++i) {
            cin >> name1 >> name2;
            if (dict.find(name1) == dict.end()) dict.insert(make_pair(name1, cnt++));
            if (dict.find(name2) == dict.end()) dict.insert(make_pair(name2, cnt++));

            int ap = find(dict[name1]);
            int bp = find(dict[name2]);

            if (ap != bp) {
                parent[bp] = ap;
                root[ap] += root[bp];
            }

            cout << root[ap] << '\n';
        }
    }

    return 0;
}