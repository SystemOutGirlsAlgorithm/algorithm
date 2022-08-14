#include <iostream>
#include <vector>
using namespace std;

int N, M;
int ans[8];

void dfs(int num, int size) {
    if (size >= M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return ;
    }
    if (num > N) {
        return ;
    }

    ans[size] = num;
    dfs(num+1, size+1);

    dfs(num+1, size);
}

int main() {
    scanf("%d %d", &N, &M);

    dfs(1, 0);
    return 0;
}