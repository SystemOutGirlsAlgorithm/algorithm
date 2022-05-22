#include <string>
#include <vector>

using namespace std;

int get_divisor_cnt(int num)
{
    int ret = 0;
    for(int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            if (i * i == num)
                ret++;
            else
                ret += 2;
        }
    }
    return (ret);
}

int solution(int left, int right) {
    int answer = 0;

    for(int i = left; i <= right; i++)
    {
        if (get_divisor_cnt(i) % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}