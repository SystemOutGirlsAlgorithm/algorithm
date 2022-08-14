#include <iostream>
using namespace std;

int N, M;
int arr[9];

void bt(int pre_num, int size) {
    arr[size] = pre_num;
    if (size >= M) {
        for (int i = 1; i <= M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return ;
    }
    for (int i = pre_num; i <= N; i++) {
        bt(i, size+1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    bt(1, 0);
    return 0;
}