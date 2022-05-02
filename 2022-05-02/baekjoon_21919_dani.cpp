#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

ll gcd (ll x, ll y) //최대공약수 알고리즘
{
    ll temp;
    if (x < y) {
        temp = x;
        x = y;
        y = temp;
    }
    while (y!=0) {
        temp = x;
        x = y;
        y = temp % y;
    }
    return x;
}

ll lcm(ll x, ll y) //최소공배수 알고리즘
{
    return (x*y) / gcd(x, y);
}

void prime_check(int n, vector<ll> &prime) //소수 판별 알고리즘
{
    bool flag = false;
    for (int i=2; i*i<=n; i++) {
        if (n%i==0) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        prime.emplace_back(n);
    }
}

int main() 
{
    ll n, temp, length;
    bool flag;
    vector <ll> prime;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> temp;
        prime_check(temp, prime); //소수만 저장
    }

    if (prime.empty()) { //소수 벡터가 비어있으면 -1 출력
        cout << "-1" << "\n";
    }

    else {
        temp = prime[0];
        length = prime.size();
        for (int i=1; i<length; i++) { //소수 벡터 크기만큼 반복 돌려가며
            temp = lcm (prime[i], temp); //여러 수의 최소공배수 구하기
        }
        cout << temp << "\n";
    }
    return 0;
}