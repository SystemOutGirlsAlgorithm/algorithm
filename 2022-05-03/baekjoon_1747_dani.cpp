#include <iostream> 
#include <vector>
#include <string>

using namespace std;

const int MAX = 1005000;

void eratos(int n, vector<int>&arr) //소수 구하기 알고리즘
{
    vector<bool> check(MAX+1, false);
    check[0] = true;
    check[1] = true;
    for (int i=2; i*i<=MAX; i++) {
        if (!check[i]) {
            for (int j=i+i; j<=MAX; j+=i) {
                check[j] = true;
            }
        }
    }
    for (int i=n; i<=MAX; i++) {
        if (!check[i]) {
            arr.emplace_back(i);
        }
    }
}

int main() 
{
    int n, length, string_len;
    string num, num_reverse;
    vector<int> prime;
    cin >> n;

    eratos(n, prime); //n보다 크거나 같은 소수 구하기
    length = prime.size();
    
    for (int i=0; i<length; i++) {
        num = to_string(prime[i]);
        string_len = num.length();
        num_reverse = num[string_len-1]; //맨 끝 숫자 먼저 string에 대입

        for (int j=string_len-2; j>=0; j--) { //숫자 뒤집어주기 (끝에서 두번째부터)
            num_reverse += num[j];
        }

        if (num == num_reverse) {
            cout << num << "\n";
            break;
        }
    }
    return 0;
}