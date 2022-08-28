#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    string str;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> m;
        vector<bool> valid(m);
        priority_queue<pair<int, int>> maxpq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;

        for (int j = 0; j < m; j++) {
            char sign;
            int num;
            cin >> sign >> num;
            
            if (sign == 'I') {
                maxpq.push({num, j});
                minpq.push({num, j});
                valid[j] = true;
            }
            
            if (sign == 'D') {
                if (num == 1) {
                    while (!maxpq.empty() && valid[maxpq.top().second] == false) maxpq.pop();
                    if (!maxpq.empty()) {
                        valid[maxpq.top().second] = false;
                        maxpq.pop();
                    }
                }
                else if (num == -1) {
                    while (!minpq.empty() && valid[minpq.top().second] == false) minpq.pop();
                    if (!minpq.empty()) {
                        valid[minpq.top().second] = false;
                        minpq.pop();
                    }
                }
            }
        }
        
        while (!maxpq.empty() && valid[maxpq.top().second] == false) maxpq.pop();
        while (!minpq.empty() && valid[minpq.top().second] == false) minpq.pop();
        if (maxpq.empty() && minpq.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << maxpq.top().first << " " << minpq.top().first << "\n";
        }
    }
    
    return 0;
}