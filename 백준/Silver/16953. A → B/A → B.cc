#include<bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int A, B;
map<long long, int> m;

int main(void) {
	cin >> A >> B;
	m[A] = 1;

	queue<pair<long long,int>> q;
	q.push({ A,1 });
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (now == B) {
			cout << cnt << "\n";
			return 0;
		}
		long long x = now * 2;
		if (x <= B && m[x] == 0) {
			m[x] = 1;
			q.push({ x, cnt + 1 });
		}
		long long y = (long long)now * 10 + 1;
		if (y <= B && m[y] == 0) {
			m[y] = 1;
			q.push({ y, cnt + 1 });
		}
	}
	cout << -1 << "\n";
	return 0;
}