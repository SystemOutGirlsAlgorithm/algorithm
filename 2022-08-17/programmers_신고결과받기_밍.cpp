#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<string, set<string>> report_list;
    map<string,int> cnt;
    string reporter, reported;
    for (auto i: report) {
        for (int j = 0; j < i.size(); j++) {
            if (i[j] == ' ') {
                reporter = i.substr(0, j);
                reported = i.substr(j + 1);
            }
        }
        
        auto res = report_list[reporter].insert(reported);
        if (res.second)
            cnt[reported]++;
    }
    
    map<string, int> rescnt;
    for (auto i: report_list) {
        for (auto j: i.second) {
            if (cnt[j] >= k)
                rescnt[i.first]++;
        }
    }
    
    int index = 0;
    for (auto i: id_list) {
        answer[index] = rescnt[i];
        index++;
    }
    
    return answer;
}