#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> cnt;
    for (auto i: nums)
        cnt[i]++;
    
    if (cnt.size() > nums.size() / 2)
        answer = nums.size() / 2;
    else
        answer = cnt.size();
    return answer;
}