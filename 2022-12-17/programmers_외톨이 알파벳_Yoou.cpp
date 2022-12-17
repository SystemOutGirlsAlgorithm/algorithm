// 프로그래머스 [PCCP 모의고사 1] 1번 외톨이 알파벳

#include <string>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

set<char> answerSet;
bool isChecked[27];
bool isAlone[27];
bool flag = false;

void findAlone(string &input_string) {
    auto iter = input_string.begin();
    while (iter != input_string.end()) {
        char curr = *iter;
        if (isAlone[curr - 'a']) {
            iter++;
            continue;
        }
        else if (isChecked[curr- 'a']) {
            answerSet.insert(curr);
            isAlone[curr - 'a'] = true;
        }
        isChecked[curr- 'a'] = true;
        iter ++;
        while (iter != input_string.end() && curr == *iter)
            iter++;
    }
}

string makeAnswer() {
    if (answerSet.empty()) {
        return "N";
    }
    string ret;
    for(auto iter = answerSet.begin(); iter != answerSet.end(); iter++)
        ret.push_back(*iter);
    return ret;
}

string solution(string input_string) {
    string answer = "";
    memset(isChecked, false, sizeof(isChecked));
    memset(isAlone, false, sizeof(isAlone));
    findAlone(input_string);
    answer = makeAnswer();
    return answer;
}