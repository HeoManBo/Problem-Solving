#include<bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int N, M;
long long parent[101010];

int find(int u) {
	if (parent[u] == u) {
		return u;
	}
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	int a = find(u);
	int b = find(v);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

vector<pair<int, pair<int, int>>> g;

int main(void) {
	cin >> N >> M;
	long long total_cost = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g.push_back({ c,{a,b} });
		total_cost += c;
	}
	sort(g.begin(), g.end());
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	long long ans = 0;
	for (int i = 0; i < g.size(); i++) {
		int u = g[i].second.first;
		int v = g[i].second.second;
		int c = g[i].first;
		if (find(u) != find(v)) {
			merge(u, v);
			ans += c;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (find(parent[i]) != find(1)) {
			cout << "-1\n";
			return 0;
		}
	}


	cout << total_cost - ans << "\n";

	return 0;
}