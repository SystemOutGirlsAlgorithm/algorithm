using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long total = 0;
    int curr_price = 0;
    
    for(int i = 1; i <= count; i++)
    {
        curr_price += price;
        total += curr_price;
    }
    if (total > money)
        answer = total - money;
    else
        answer = 0;
    
    return answer;
}