#include <iostream>

using namespace std;

typedef long long int ll;

ll gcd(ll x, ll y)
{
	ll temp;
	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}
	while (y != 0)
	{
		temp = x;
		x = y;
		y = temp % y;
	}
	return x;
}

int main()
{
    ll a, b, gcd_n;
    cin >> a >> b;

    gcd_n = gcd(a, b);
    for (int i=0; i<gcd_n; i++) cout << "1";
    
    return 0;
}