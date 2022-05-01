/*#include <iostream>

using namespace std;

int main() {
	int T, N, M;
	long long output = 1;
	cin >> T;
	for (int i = 0; i < T; i++) {
		output = 1;
		cin >> N >> M;

		if (N > (M / 2)) N = M - N;
		for (int j = M; j > M-N; j--) output *= j;
		for (int j = N; j > 0; j--) output /= j;

		cout << output<<"\n";
	}
	return 0;
}*/