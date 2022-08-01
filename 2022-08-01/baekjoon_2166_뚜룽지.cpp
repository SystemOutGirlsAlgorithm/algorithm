#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N;
double ans = 0;
vector<pair<double, double> > arr;

double ccw(pair<double, double> point1, pair<double, double> point2, pair<double, double> point3) {
    return point1.first*point2.second+point2.first*point3.second+point3.first*point1.second -
            (point2.first*point1.second+point3.first*point2.second+point1.first*point3.second);
}

int main() {
    cin >> N;

    double x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        arr.push_back(make_pair(x, y));
    }

    pair<double, double> A = arr[0];
    
    for (int i = 2; i < N; i++) {
        pair<double, double> B = arr[i];
        pair<double, double> C = arr[i-1];
        
        ans += ccw(A, B, C)/2;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans);
    return 0;
}