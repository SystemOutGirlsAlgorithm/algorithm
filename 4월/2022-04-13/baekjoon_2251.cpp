#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stdio.h>
#include <math.h>
#include <sstream>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

bool visited[205][205][205];

struct bottle {
    int a, b, c;
};

int main() 
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    // 1 2 8 9 10
    vector<int> ans;
    queue<bottle> q;
    q.push({0, 0, c});

    while (!q.empty()) {
        bottle curr = q.front();
        q.pop();
        
        if (visited[curr.a][curr.b][curr.c])
            continue;
        visited[curr.a][curr.b][curr.c] = true;
        
        if (curr.a == 0)
            ans.push_back(curr.c);

        if (curr.a + curr.b > b)
            q.push({curr.a + curr.b - b, b, curr.c});
         else
            q.push({0, curr.a + curr.b, curr.c});

         if (curr.a + curr.c > c)
            q.push({curr.a + curr.b - c, curr.b, c});
         else
            q.push({0, curr.b, curr.a + curr.c});

         if (curr.b + curr.a > a)
            q.push({a, curr.b + curr.a - a, curr.c});
         else
            q.push({curr.b + curr.a, 0, curr.c});

         if (curr.b + curr.c > c)
            q.push({curr.a, curr.b + curr.c - c, c});
         else
            q.push({curr.a, 0, curr.b + curr.c});

         if (curr.c + curr.a > a)
            q.push({a, curr.b, curr.c + curr.a - a});
         else
            q.push({curr.c + curr.a, curr.b, 0});

         if (curr.c + curr.b > b)
             q.push({curr.a, b, curr.c + curr.b - b});
         else
             q.push({curr.a, curr.c + curr.b, 0});   
    }
    
    sort(all(ans));
    for (auto res: ans)
        printf("%d ", res);
    
    return 0;
}