#include<bits/stdc++.h>

using namespace std;

int N;

bool isDecrease(long long x) {
	string s = to_string(x);

	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] <= s[i + 1]) {
			return false;
		}
	}

	return true;
}

int main(void)
{
	cin >> N;
	int cnt = 9;
	if (N <= 10) {
		cout << N << '\n';
		return 0;
	}

	queue<long long> q;
	for (int i = 0; i <= 9; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		long long cur = q.front();
		q.pop();

		int last_number = cur % 10;

		for (int add = 0; add < last_number; add++) {
			q.push(cur * 10 + add);
			cnt++;
			if (cnt == N) {
				cout << cur * 10 + add << '\n';
				return 0;
			}
		}
	}

	cout << "-1\n";

	return 0;
}