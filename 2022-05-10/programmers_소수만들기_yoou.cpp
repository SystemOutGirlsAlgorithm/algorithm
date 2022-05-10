#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

bool prime_array[3001];

void eratos()
{
    memset(prime_array, true, sizeof(prime_array));
    for(int i = 2; i <= 3000; i++)
    {
        if (prime_array[i])
        {
            for(int j = 2; j * i <= 3000; j++)
                prime_array[j * i] = false;
        }    
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    
    eratos();
    for(int a = 0; a < nums.size() - 2; a++)
    {
        for(int b = a + 1; b < nums.size() - 1; b++)
        {
            for(int c = b + 1; c < nums.size(); c++)
            {
                if (prime_array[nums[a] + nums[b] + nums[c]])
                    answer++;
            }
        }
    }
    
    return answer;
}