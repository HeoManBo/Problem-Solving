#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int parent[1010];
int cost[1010][1010];
vector<pair<int, pair<int, int>>> edges;

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	int up = find(u);
	int vp = find(v);

	if (up != vp) {
		parent[vp] = up;
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 2; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (find(a) != find(b)) {
			merge(a, b);
		}
	}

	for (int i = 1; i <= n; i++ ) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (i == j) continue;
			edges.push_back({ cost[i][j], {i,j} });
		}
	}

	sort(edges.begin(), edges.end());

	int ans = 0;
	vector<pair<int, int>> connect;

	for (auto x : edges) {
		int u = x.second.first;
		int v = x.second.second;
			
		if (find(u) != find(v)) {
			merge(u, v);
			connect.push_back({ u,v });
			ans += x.first;
		}
	}

	if (connect.size() == 0) {
		cout << "0 0\n";
	}
	else {
		cout << ans << ' ' << connect.size() << '\n';
		for (auto x : connect) {
			cout << x.first << ' ' << x.second << '\n';
		}
	}

	return 0;
}