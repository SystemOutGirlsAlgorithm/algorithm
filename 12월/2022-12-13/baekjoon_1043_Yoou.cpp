// 백준 1043 거짓말

/*
	당연히, 어떤 사람이 어떤 파티에서는 진실을 듣고, 또다른 파티에서는 과장된 이야기를 들었을 때도 지민이는 거짓말쟁이로 알려지게 된다.
    지민이는 이런 일을 모두 피해야 한다.
	---
	진실을 아는 사람과 한번이라도 함께 파티에 참석한 사람은 (순서 상관 없음) 무조건 혼자 있더라도 진실을 들어야 한다.
	따라서 M * M 번 반복하며 계속해서 거짓을 들을 수 있는 사람들을 업데이트해줘야 함.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int ans = 0;
set<int> knowTruth;					// 그 이야기의 진실을 아는 사람들의 목록
vector<vector<int> > participants;	// 각 파티의 참석자

bool canLie(int idx, bool update) {
	bool canLieFlag = true;
	// 파티 참석자들 중에 진실을 아는 사람이 있는지 확인
	for(auto iter = participants[idx].begin(); iter != participants[idx].end(); iter++) {
		if (knowTruth.find(*iter) != knowTruth.end()) {
			canLieFlag = false;
			break;
		}
	}
	// 진실을 말해야 하는 경우 파티 참석자들을 진실을 아는 사람들로 업데이트
	if (update && canLieFlag == false) {
		for(auto iter = participants[idx].begin(); iter != participants[idx].end(); iter++) 
			knowTruth.insert(*iter);
	}
	return canLieFlag;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, cnt, input;
	cin >> N >> M;
	cin >> cnt;
	for(int i = 0; i < cnt; i++) {
		cin >> input;
		knowTruth.insert(input);
	}
	participants.resize(M);
	for(int i = 0; i < M; i++) {
		cin >> cnt;
		for(int j = 0; j < cnt; j++) {
			cin >> input;
			participants[i].push_back(input);
		}
	}
	// 앞서서 거짓을 들었던 사람이 뒤에서 진실을 들으면 안되므로
	// M번 반복하면서 앞서서 거짓을 들었던 사람이 뒤에서 진실을 듣는 경우를 찾아준다.
	for(int k = 0; k < M; k++){
		for(int i = 0; i < M; i++) {
			canLie(i, true);
		}
	}
	// 진실을 알아야 하는 사람들 목록 확정.
	// 세어주기만 하면 되므로 update 파라미터를 false로
	for(int i = 0; i < M; i++) {
		if (canLie(i, false))
			ans++;
	}
	cout << ans;
	return 0;
}