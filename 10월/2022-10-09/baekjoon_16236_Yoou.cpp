#include <iostream>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

class BabyShark {
	public:
		int ans = 0;
		int size = 2;
		int eat_cnt = 0;
		pair<int, int> pos;
};

int N;
BabyShark S;
int map[20][20];
int dist[20][20];
bool visited[20][20];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<int, int> > Q;

void init_info(void) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			dist[i][j] = -1;
			visited[i][j] = false;
		}
	}
}

void eat(void) {
	pair<int, int> fish_pos;
	int fish_dist = INT_MAX;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if (dist[i][j] == -1 || fish_dist <= dist[i][j])
				continue;
			fish_dist = dist[i][j];
			fish_pos = make_pair(i, j);
		}
	}
	S.ans += fish_dist;
	S.eat_cnt++;
	if (S.eat_cnt == S.size) {
		S.eat_cnt = 0;
		S.size++;
	}
	map[fish_pos.first][fish_pos.second] = 0;
	S.pos = fish_pos;
	return;
}

bool move(void) {
	int size, y, x, new_y, new_x, curr_dist;
	bool eat_flag = false;
	curr_dist = 1;
	while (!Q.empty()) {
		size = Q.size();
		for (int k = 0; k < size; k++) {
			y = Q.front().first;
			x = Q.front().second;
			Q.pop();
			for (int d = 0; d < 4; d++) {
				new_y = y + dy[d];
				new_x = x + dx[d];
				if (new_y < 0 || new_x < 0 || new_y >= N || new_x >= N || visited[new_y][new_x])
					continue;
				visited[new_y][new_x] = true;
				if (map[new_y][new_x] == 0 || map[new_y][new_x] == S.size)
					Q.push(make_pair(new_y, new_x));
				else if (map[new_y][new_x] < S.size)
				{
					dist[new_y][new_x] = curr_dist;
					eat_flag = true;
				}
			}
		}
		curr_dist++;
	}
	if (eat_flag)
		eat();
	return(eat_flag);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	init_info();
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				S.pos.first = i;
				S.pos.second = j;
			}
		}	
	}
	Q.push(S.pos);
	visited[S.pos.first][S.pos.second] = true;
	while (move()) {
		init_info();
		Q.push(S.pos);
		visited[S.pos.first][S.pos.second] = true;
	}
	cout << S.ans;
	return (0);
}
