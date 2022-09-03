#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    queue<int> q;
    
    cin >> n >> m;
    
    
    cout << "<" << m;

    for (int i = m + 1; i <= n; i++)
        q.push(i);
    
    for (int i = 1; i < m; i++) {
        q.push(i);
    }
    
    int cnt = 1;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        if (cnt == m) {
            cout << ", " << temp;
            cnt = 1;
        }
        else {
            q.push(temp);
            cnt++;
        }
    }
    
    cout << ">";
    
    return 0;
}