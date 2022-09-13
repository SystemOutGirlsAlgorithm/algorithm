#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int points[26] = {0, };
    char op1, op2;
    for(int i = 0; i < survey.size(); i++)
    {
        op1 = survey[i][0];
        op2 = survey[i][1];
        if (choices[i] < 4)
            points[op1 - 'A'] += 4 - choices[i];
        else
            points[op2 - 'A'] += choices[i] - 4;
    }
    char type;
    points['R' - 'A'] >= points['T' - 'A'] ? type = 'R' : type = 'T';
    answer.push_back(type);
    points['C' - 'A'] >= points['F' - 'A'] ? type = 'C' : type = 'F';
    answer.push_back(type);
    points['J' - 'A'] >= points['M' - 'A'] ? type = 'J' : type = 'M';
    answer.push_back(type);
    points['A' - 'A'] >= points['N' - 'A'] ? type = 'A' : type = 'N';
    answer.push_back(type);
    return answer;
}