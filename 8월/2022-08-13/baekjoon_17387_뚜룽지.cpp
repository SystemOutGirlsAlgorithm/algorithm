#include <iostream>
#include <vector>
using namespace std;

vector<pair<double, double> > point;


double ccw(pair<double, double> point1, pair<double, double> point2, pair<double, double> point3) {
    return point1.first*point2.second+point2.first*point3.second+point3.first*point1.second -
            (point2.first*point1.second+point3.first*point2.second+point1.first*point3.second);
}

int compare() {
    double dir1 = ccw(point[0], point[1], point[2]) * ccw(point[0], point[1], point[3]);
    double dir2 = ccw(point[2], point[3], point[0]) * ccw(point[2], point[3], point[1]);
    if (dir1 <= 0 && dir2 <= 0) {
        if (dir1 == 0 && dir2 == 0) {
            if (point[0] > point[1]) swap(point[0], point[1]);
            if (point[2] > point[3]) swap(point[2], point[3]);
            return point[0] <= point[3] && point[2] <= point[1];
        }
        return 1;
    }
    return 0;
}

int main() {
    double x, y;
    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        point.push_back(make_pair(x, y));
    }
    cout << compare();

}