#include<bits/stdc++.h>

using namespace std;

int N, cmd[1'111'111];

int main(void) {
	cin >> N;
	deque<int> dq;
	int card = 1;
	for (int i = 1; i <= N; i++) {
		cin >> cmd[i];
	}
	for (int i = N; i >= 1; i--) {
		if (cmd[i] == 1) {
			dq.push_back(card);
		}
		else if (cmd[i] == 2) {
			int tmp = dq.back();
			dq.pop_back();
			dq.push_back(card);
			dq.push_back(tmp);
		}
		else {
			dq.push_front(card);
		}
		card++;
	}

	for (int i = N - 1; i >= 0; i--) {
		cout << dq[i] << ' ';
	}
	cout << '\n';
	return 0;
}