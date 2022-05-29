#include <string>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int ans_a = 0, ans_b = 0;
    int a, b;
    
    for(int i = 0; i < sizes.size(); i++)
    {
        a = sizes[i][0];
        b = sizes[i][1];
        if (a > b)
            swap(&a, &b);
        if (a > ans_a)
            ans_a = a;
        if (b > ans_b)
            ans_b = b;
    }
    answer = ans_a * ans_b;
    return answer;
}