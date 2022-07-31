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


int main() {
    // 과목 비트마스크 저장
    int n;
    scanf("%d", &n);
    
    vector<bitset<55>> subject(n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        
        for (int j = 0; j < k; j++) {
            int t;
            scanf("%d", &t);
            
            subject[i][t] = 1;
        }
    }
    
    // 학생 비트마스크 저장
    int m;
    scanf("%d", &m);
    
    vector<bitset<55>> student(m);
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        
        for (int j = 0; j < k; j++) {
            int t;
            scanf("%d", &t);
            
            student[i][t] = 1;
        }
    }
    
    // 과목과 학생 비교
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if ((student[i] & subject[j]) == subject[j])
                count++;
        }
        printf("%d\n", count);
    }
    
    
    
    return 0;
}
