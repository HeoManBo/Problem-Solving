#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int N, M;
int parent[2222], enemy[2222];

int find(int u) {
	if (parent[u] == u) {
		return u;
	}
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		parent[v] = u;
	}
}

int main(void)
{

	cin >> N >> M;
	int ans = 1;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		//적대관계로 표시했는데 같은 집합이면 --> FALSE
		if (find(u) == find(v)) {
			ans = 0;
			break;
		}

		int& uE = enemy[u];
		int& vE = enemy[v];

		if (uE == 0) {
			uE = v;
		}
		else {
			merge(uE, v);
		}

		if (vE == 0) {
			vE = u;
		}
		else {
			merge(vE, u);
		}
	}

	cout << ans << '\n';
	return 0;
}
