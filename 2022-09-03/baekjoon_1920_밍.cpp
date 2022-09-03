#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    set<int> s;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> m;
        s.insert(m);
    }
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >>m;
        if (s.find(m) != s.end()) 
            cout << "1\n";
        else
            cout << "0\n";
    }
    
    
    return 0;
}