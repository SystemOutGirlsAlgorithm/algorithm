#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
char board[5][35];
vector<vector<int> > number_shape = { {7, 5, 5, 5, 7}
                                    , {1, 1, 1, 1, 1}
                                    , {7, 1, 7, 4, 7}
                                    , {7, 1, 7, 1, 7}
                                    , {5, 5, 7, 1, 1}
                                    , {7, 4, 7, 1, 7}
                                    , {7, 4, 7, 5, 7}
                                    , {7, 1, 1, 1, 1}
                                    , {7, 5, 7, 5, 7}
                                    , {7, 5, 7, 1, 7} };

vector<vector<int> > number_change = { {0, 1, 4, 5, 7}
                                     , {1, 5, 7}
                                     , {7}
                                     , {7}
                                     , {4, 5, 7}
                                     , {5, 7}
                                     , {7}
                                     , {7} };


vector<int> line = {0, 0, 0, 0, 0};
int pos_have[9][10];
double pos_sum[9];
int pos_cnt[9];
int pos = 0;

void number_check() {
    for (int i = 0; i < 10; i++) {
        if (line == number_shape[i]) {
            if (!pos_have[pos][i]) {
                pos_have[pos][i] = 1;
                pos_sum[pos] += i;
                pos_cnt[pos]++;
            }
        }
    }
}

void number_scan(int h) {
    number_check();
    if (h > 5) {
        return ;
    }
    int line_num = line[h];
    for (int i = 0; i < number_change[line[h]].size(); i++) {
        line[h] = number_change[line[h]][i];
        number_scan(h+1);
        line[h] = line_num;
    }
}

void possible_num() {
    for (; pos < N; pos++) {
        int p = 4*pos;
        for (int h = 0; h < 5; h++) {
            int line_num = 0;
            for (int w = p; w < p+3; w++) {
                line_num *= 2;
                if (board[h][w] == '#') {
                    line_num += 1;
                }
            }
            line[h] = line_num;
        }
        number_scan(0);
    }
}

void calc() {
    double sum = 0;
    int size = 1;
    for (int i = 0; i < N; i++) {
        sum += (pos_sum[i]/pos_cnt[i])*pow(10, N-i-1);
        size *= pos_cnt[i];
    }
    cout << fixed;
    cout.precision(5);
    if (size == 0) cout << -1;
    else cout << sum;

}


int main() {
    /* INPUT */
    cin >> N;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4*N-1; j++) {
            cin >> board[i][j];
        }
    }

    /* SOLUTION */
    possible_num();
    calc();
    return 0;
}