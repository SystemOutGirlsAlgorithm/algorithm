#include <string>

using namespace std;

string solution(int num)
{
    if (num % 2 == 0)
    {
        return "Even";
    }
    else
    {
        return "Odd";
    }
}

/*
 *  다른 방법
 *  비트 연산자 &을 이용하면 홀수, 짝수 구별 (LSB == 0: 짝수, LSB == 1: 홀수 )
 */
