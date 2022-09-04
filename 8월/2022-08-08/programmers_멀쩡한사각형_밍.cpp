#include <algorithm>
#include <numeric>
using namespace std;

long long solution(int w,int h) {    
    long long answer = ((long long)w * h) - ((long long)w + h - gcd(w, h));
    return answer;
}