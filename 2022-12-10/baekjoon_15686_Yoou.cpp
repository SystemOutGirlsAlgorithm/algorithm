// 백준 15686 치킨 배달

/*
	1. 각 집의 모든 치킨집 사이의 거리를 구한다.
	2. 총 치킨집 중에서 M개를 고르는 조합을 모두 탐색하면서 치킨거리의 최솟값을 업데이트한다.
	(결론은 조합을 구하는 것이 관건)
*/

#include <iostream>
#include <cmath>		// abs
#include <vector>
#include <utility>		// pair
#include <climits>		// INT_MAX
#include <cstring>		// memset
#include <algorithm>	// min
using namespace std;

bool picked[13];
vector<int> pickedChicken;
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;
vector<vector<int> > chickenDistance;
int N, M;
int ans = INT_MAX;

int getDistance(pair<int, int> &pos1, pair<int, int> &pos2) {
	return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

void initInfo(void) {
	int input;
	memset(picked, false, sizeof(picked));
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> input;
			if (input == 1)
				house.push_back(make_pair(i, j));
			else if (input == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	// 집마다 모든 치킨집까지의 거리 구해서 저장
	chickenDistance.resize(house.size());
	for(int i = 0; i < house.size(); i++) {
		for(int j = 0; j < chicken.size(); j++)
			chickenDistance[i].push_back(getDistance(house[i], chicken[j]));
	}
}

// 뽑힌 치킨집들로 만들어진 치킨거리의 최솟값을 구한다.
int getChickenDistance(void) {
	int ret = 0;
	for(int i = 0; i < house.size(); i++) {
		int thisDistance = INT_MAX;
		for(int j = 0; j < pickedChicken.size(); j++)
			thisDistance = min(thisDistance, chickenDistance[i][pickedChicken[j]]);
		ret += thisDistance;
	}
	return ret;
}

// 조합구현 (익숙해집시다...)
void selectChicken(int idx, int cnt)
{
	// M개를 골랐으면 계산된 값을 지금까지의 답과 비교해서 업데이트한다.
	if (cnt == M) {
		ans = min(ans, getChickenDistance());
		return;
	}
	for(int i = idx; i < chicken.size(); i++) {
		if (picked[i])
			continue;
		picked[i] = true;
		pickedChicken.push_back(i);
		selectChicken(i, cnt + 1);
		picked[i] = false;	// 악악악 까먹지 말라
		pickedChicken.pop_back();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	initInfo();
	selectChicken(0, 0);
	cout << ans;
	return 0;
}