#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    
    int nonum = 0, same = 0;
    
    sort(win_nums.begin(), win_nums.end());
    
    for (auto i: lottos) {
        if (i == 0) {
            nonum += 1;
            continue;
        }
        for (auto j: win_nums) {
            if (i == j) {
                same += 1;
                break;
            }
            else if (i < j)
                break;
        }
    }
    
    int maxsum = nonum + same, minsum = same;
    
    // 최고순위 범위 설정(1~6)
    if (maxsum > 6) maxsum = 6;
    else if (maxsum < 1) maxsum = 1;
    
    // 최저순위 범위 설정(1~6)
    if (minsum < 1) minsum = 1;
    
    answer[0] = 7 - maxsum;
    answer[1] = 7 - minsum;
    
    return answer;
}