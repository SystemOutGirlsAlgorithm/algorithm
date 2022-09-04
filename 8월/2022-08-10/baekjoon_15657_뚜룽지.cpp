#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int list[9];
int ans[9];

int promising(int size, int num) {
    for (int i = 1; i <= size; i++) {
        if (ans[i] > num) return 0;
    }
    return 1;
}

void bt(int pre_num, int size) {
    ans[size] = pre_num;
    if (size >= M) {
        for (int i = 1; i <= M; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return ;
    }
    for (int i = 1; i <= N; i++) {
        if (promising(size, list[i])) bt(list[i], size+1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &list[i]);
    }
    sort(&list[1], &list[1]+N);
    list[0] = 0;
    bt(0, 0);
    return 0;
}