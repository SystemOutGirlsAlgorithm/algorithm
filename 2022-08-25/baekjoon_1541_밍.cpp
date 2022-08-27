#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "";
    cin >> str;
    
    int result = 0, num = 0, sign = 1;
    for (auto i: str) {
        if (i != '+' && i != '-') {
            num = num * 10 + (i - 48);
        }
        else {
            result += num * sign;
            num = 0;
            
            if (i == '-')
                sign = -1;
        }
    }
    result += num * sign;
    cout << result;
}