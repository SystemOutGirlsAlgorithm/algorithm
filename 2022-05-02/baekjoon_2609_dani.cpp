#include <iostream>
using namespace std;

int gcd(int a, int b) 
{
    int temp;
    if (a<b) {
        temp = a;
        a = b;
        b = temp;
    }
    while(b!=0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int lcm(int a, int b) 
{
    return (a*b)/gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b;
    cin >> a >> b;
    cout << gcd(a,b) << "\n";
    cout << lcm(a,b) << "\n";
    return 0;
}