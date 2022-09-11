using namespace std;

int solution(int n)
{
    int answer = 0;

    for (int i = 2; i < n; ++i)
    {
        if ((n - 1) % i == 0)
        {
            answer = i;
            break;
        }
    }

    return answer;
}
