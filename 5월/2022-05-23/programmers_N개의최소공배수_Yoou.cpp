#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
        return (b);
    else
        return (gcd(b, a % b));
}

int lcm(int a, int b)
{
    return (a * b / gcd(a, b));
}

int solution(vector<int> arr) {
    int answer = 0;
    
    answer = arr[0];
    for(int i = 1; i < arr.size(); i++)
    {
        if (answer > arr[i])
            answer = lcm(answer, arr[i]);
        else
            answer = lcm(arr[i], answer);
    }
    return answer;
}