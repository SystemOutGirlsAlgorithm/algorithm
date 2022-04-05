#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#define xx first
#define yy second
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

vector<int> adj[30];
int dot = 'Z' + 1;

void preorderTraversal(int curr)
{
    printf("%c", curr + 'A');
    if (adj[curr][0] != dot) {
        preorderTraversal(adj[curr][0]);
    }
    if (adj[curr][1] != dot) {
        preorderTraversal(adj[curr][1]);
    }
}

void inorderTraversal(int curr)
{
    if (adj[curr][0] != dot) {
        inorderTraversal(adj[curr][0]);
    }
    printf("%c", curr + 'A');
    if (adj[curr][1] != dot) {
        inorderTraversal(adj[curr][1]);
    }
}

void postorderTraversal(int curr)
{
    if (adj[curr][0] != dot) {
        postorderTraversal(adj[curr][0]);
    }
    if (adj[curr][1] != dot) {
        postorderTraversal(adj[curr][1]);
    }
    printf("%c", curr + 'A');
}

int main() 
{
    int n;
    scanf("%d", &n);

    string str;
    getline(cin, str);
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        
        int a = str[0] == '.' ? dot : str[0] - 'A';
        int b = str[2] == '.' ? dot : str[2] - 'A';
        int c = str[4] == '.' ? dot : str[4] - 'A';
        
        adj[a].push_back(b);
        adj[a].push_back(c);
    }
    
    preorderTraversal(0);
    cout << "\n";
    inorderTraversal(0);
    cout << "\n";
    postorderTraversal(0);
    
    return 0;
}