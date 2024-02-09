#include<bits/stdc++.h>

using namespace std;

int friends[1'000'000], N , K, M;

int find(int u) {
	if (friends[u] == u) {
		return u;
	}
	return friends[u] = find(friends[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		friends[v] = u;
	}
}

void init() {
	for (int i = 0; i < 1'000'000; i++) {
		friends[i] = i;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		init();
		cin >> N;
		cin >> K;
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			merge(a, b);
		}
		cin >> M;
		cout << "Scenario " << i << ":\n";
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			if (find(a) == find(b)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		cout << "\n";
	}

	return 0;
}