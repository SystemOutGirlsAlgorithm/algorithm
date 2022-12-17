// 프로그래머스 [PCCP 모의고사 1] 2번 체육대회

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> ability) {
    int answer = 0;
    vector<int> student_list;
    for(int i = 0; i < ability.size(); i++)
        student_list.push_back(i);
    int event_cnt = ability[0].size();

    // 학생수 중 종목 수(event_cnt)만큼 뽑는 "순열"
    while(1)
    {
        int sum = 0;
        for(int i = 0; i < event_cnt; i++)
            sum += ability[student_list[i]][i];
        answer = max(answer, sum);
        reverse(student_list.begin() + event_cnt, student_list.end());
        if(!next_permutation(student_list.begin(), student_list.end()))
            break;
    }
    return answer;
}