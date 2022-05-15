#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string word;
	int length;
	bool flag = false;

	while (1) {
		stack<int> s;
		flag = false;
		getline(cin, word, '.');
		cin.ignore();

		length=word.size();

		if (length==0) break;

		for (int i=0; i<length; i++) {

			if (word[i]=='(' || word[i]=='[') {
				s.push(word[i]);
			}

			else if (word[i]==')') {
				if (s.empty() || s.top()!='(') {
					flag = true;
					break;
				}
				s.pop();
			}

			else if (word[i]==']') {
				if (s.empty() || s.top()!='[') {
					flag = true;
					break;
				}
				s.pop();
			}
		}

		if (flag == true || !s.empty()) {
			cout << "no" << "\n";
		}
		else cout << "yes" << "\n";
		
	}

	return 0;
}