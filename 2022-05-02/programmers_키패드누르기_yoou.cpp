#include <string>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    pair<int, int> pos_right = {3, 2};
    pair<int, int> pos_left = {3, 0};
    pair<int, int> pos_list[10] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
    int dist_right, dist_left, target;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        target = numbers[i];
        if (target == 1 || target == 4 || target == 7)
        {
            answer.push_back('L');
            pos_left = pos_list[target];
        }
        else if (target == 3 || target == 6 || target == 9)
        {
            answer.push_back('R');
            pos_right = pos_list[target];
        }
        else
        {
            dist_right = abs(pos_right.first - pos_list[target].first) + abs(pos_right.second - pos_list[target].second);
            dist_left = abs(pos_left.first - pos_list[target].first) + abs(pos_left.second - pos_list[target].second);
            if (dist_right < dist_left || (dist_right == dist_left && hand == "right"))
            {
                answer.push_back('R');
                pos_right = pos_list[target];
            }
            else
            {
                answer.push_back('L');
                pos_left = pos_list[target];
            }
        }  
    }
    
    return answer;
}