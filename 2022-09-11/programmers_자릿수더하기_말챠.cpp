using namespace std;

int solution(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

/*
 *  다른 방법
 *  n을 string으로 바꿔서 순회하며 '0'과의 ASCII코드 차를 더해주면 됨
 */
