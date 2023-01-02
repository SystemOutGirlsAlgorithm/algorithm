// 프로그래머스 [PCCP 모의고사 1] 3번 유전법칙

#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;
std::string memo[3][5];

string getAnswer(int n, int p) {
    cout << n;
    if (n <= 2)
        return memo[n][p];
    int parent_num; // 부모가 윗세대에서 몇번째 자식
    int my_num; // 현재 세대에서 나는 몇번째 자식
    if (p % 4 == 0) {
        parent_num = p / 4;
        my_num = 4;
    }
    else {
        parent_num = p / 4 + 1;
        my_num = p - (parent_num - 1) * 4;
    }
    string parent = getAnswer(n - 1, parent_num);
    string me;
    if (parent == "RR")
        return "RR";
    else if (parent == "rr")
        return "rr";
    else {
        if (my_num == 1)
            return "RR";
        else if (my_num == 4)
            return "rr";
        else
            return "Rr";
    }
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    memo[1][1] = "Rr";
    memo[2][1] = "RR";
    memo[2][2] = "Rr";
    memo[2][3] = "Rr";
    memo[2][4] = "rr";
    for(int i = 0; i < queries.size(); i++) {
        answer.push_back(getAnswer(queries[i][0], queries[i][1]));
    }
    return answer;
}