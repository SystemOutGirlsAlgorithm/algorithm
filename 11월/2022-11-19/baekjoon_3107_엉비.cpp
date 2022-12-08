#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string input;
vector<string> ipv6, temp;

/* str 을 dlm 을 기준으로 잘라 반환 */
vector<string> split(string str, string dlm) {
    vector<string> result;
    size_t start = 0, end = str.find(dlm);

    while (end != string::npos) {
        string temp = str.substr(start, end - start);
        result.push_back(temp);
        start = end + 1;
        end = str.find(dlm, start);
    }
    result.push_back(str.substr(start, end - start));

    return result;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    /* INPUT */
    cin >> input;
    
    /* Solution */
    ipv6 = split(input, ":");

    // (1) 8자리로 만들어주기
    int size = ipv6.size();
    if (size != 8) {    // 자리가 8개가 아니라면
        size_t idx = input.find("::");  // 2번 법칙이 적용된 곳을 찾는다.
        if (idx == 0 && input.length() == 2) size = 8;  // :: 일 경우
        else if (idx == 0 || idx == input.length()-2)   // 처음이나 끝에 :: 이 있을 경우
            size = 8 - size + 2;
        else
            size = 8 - size + 1;
        
        for (int i = 0; i < ipv6.size(); ++i) {
            if (ipv6[i].length() != 0)  // 문자가 있는 경우
                temp.push_back(ipv6[i]);
            else    // 문자가 없는 경우
                while (size-- > 0) // 2번 법칙이 적용된 자리이다. 따라서 0000 을 빈 자리수만큼 채운다.
                    temp.push_back("0000");
        }

        ipv6 = temp;
    }

    // (2) 생략된 0 추가해주기
    for (int i = 0; i < ipv6.size(); ++i) {
        if ((size = ipv6[i].length()) != 4) {
            string temp = ipv6[i];
            size = 4 - size;
            while (size--)
                temp = "0" + temp;
            ipv6[i] = temp;
        }
    }

    /* OUTPUT */
    for (int i = 0; i < ipv6.size(); ++i) {
        cout << ipv6[i];
        if (i != ipv6.size()-1) cout << ":";
    }
    

    return 0;
}