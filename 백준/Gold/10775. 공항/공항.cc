#include<bits/stdc++.h>

using namespace std;

int G, P, g[101'101];
bool chk[101'101];
int parent[101'101];

int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	 u = find(u);
	 v = find(v);
	 if (u > v) swap(u, v);
	 parent[v] = u;
}


int main()
{
	cin >> G;
	cin >> P;
	for (int i = 0; i <= G; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < P; i++) {
		cin >> g[i];
	}
	int ans = 0;
	for (int i = 0; i < P; i++) {
		int p = find(g[i]);
		if (p == 0) break;
		merge(p, p - 1);
		ans++;
	}

	cout << ans << '\n';

	return 0;
}