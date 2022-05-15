#include <iostream>

using namespace std;

int main()
{
    int count=0;
    char table[8][8];
    for (int i=0; i<8; i++){
        cin >> table[i];
    }

    for (int i=0; i<8; i++) {
        for (int j=i%2; j<8; j+=2) {
            if (table[i][j] == 'F') count++;
        }
    }
    cout << count << "\n";
    return 0;
}