// 백준 17070 파이프 옮기기 1

/*
	- 완전탐색 (DFS) : 나한텐 BFS보다는 DFS가 더 흐름상으로 적절하다고 느껴짐
	- 파이프의 "끝"의 위치(1, 2)를 기준으로 일일이 돌려서 확인해준다.
	- 방문 위치를 확인 해 줄 필요가 없는 이유는 같은 위치에 도달하는 다른 방법도 모두 다른 방법으로 취급되기 때문. (최소 이동 문제가 아님.)
*/

#include <iostream>
using namespace std;

#define HORIZONTAL 0	// 가로
#define VERTICAL 1		// 세로
#define DIAGONAOL 2		// 대각

bool map[17][17]; // true : 벽
int N;
int answer = 0;

bool canMove(int r, int c) {
	if (r > N || c > N || r < 1 || c < 1)
		return false;
	if (map[r][c])
		return false;
	return true;
}

void DFS(int r, int c, int dir) {
	if (r == N && c == N) {
		answer ++;
		return;
	}
	switch(dir) {
		case HORIZONTAL:
			// 가로일 경우 이동 가능한 방향 2가지
			if (canMove(r, c + 1))
				DFS(r, c + 1, HORIZONTAL);
			if (canMove(r, c + 1) && canMove(r + 1, c) && canMove(r + 1, c + 1))
				DFS(r + 1, c + 1, DIAGONAOL);
			break;
		case VERTICAL:
			// 세로일 경우 이동 가능한 방향 2가지
			if (canMove(r + 1, c))
				DFS(r + 1, c, VERTICAL);
			if (canMove(r, c + 1) && canMove(r + 1, c) && canMove(r + 1, c + 1))
				DFS(r + 1, c + 1, DIAGONAOL);
			break;
		case DIAGONAOL:
			// 대각선일 경우 이동 가능한 방향 3가지
			if (canMove(r, c + 1))
				DFS(r, c + 1, HORIZONTAL);
			if (canMove(r + 1, c))
				DFS(r + 1, c, VERTICAL);
			if (canMove(r, c + 1) && canMove(r + 1, c) && canMove(r + 1, c + 1))
				DFS(r + 1, c + 1, DIAGONAOL);
			break;
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++ )
			cin >> map[i][j];
	}
	DFS(1, 2, HORIZONTAL);
	cout << answer;
	return 0;
}