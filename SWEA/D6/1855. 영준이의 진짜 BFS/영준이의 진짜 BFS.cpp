#include<iostream>
#include<set>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int T, N;
vector<int> tree[101010];
int depth[101010], parent[101010][22];
bool chk[101010];
const int MAX = 22;
long long ans = 0;
queue<int> qq;

//depth 계산
void bfs() {
	queue<int> q;
	q.push(1);
	depth[1] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : tree[now]) {
			if (depth[next] == -1) {
				depth[next] = depth[now] + 1;
				parent[next][0] = now;
				q.push(next);
			}
		}
	}
}

void visit_order() {
	memset(chk, 0, sizeof(chk));
	queue<int> q;
	q.push(1);
	qq.push(1);
	chk[1] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : tree[now]) {
			if (!chk[next]) {
				q.push(next);
				qq.push(next);
				chk[next] = true;
			}
		}
	}

	return;
}

void connectParent() {
	for (int k = 0; k < MAX - 1; k++) {
		for (int i = 1; i <= N; i++) {
			if (parent[i][k] != -1) {
				parent[i][k + 1] = parent[parent[i][k]][k];
			}
		}
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	int diff = depth[u] - depth[v];

	for (int i = 0; diff != 0; i++) {
		if (diff % 2 == 1) {
			u = parent[u][i];
		}
		diff /= 2;
	}

	if (u != v) {
		for (int i = MAX - 1; i >= 0; i--) {
			if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}

	return u;
}

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		ans = 0;
		memset(depth, -1, sizeof(depth));
		memset(parent, -1, sizeof(parent));
		cin >> N;
		for (int i = 2; i <= N; i++) {
			int p; cin >> p;
			tree[p].push_back(i);
			tree[i].push_back(p);
		}
		for (int i = 1; i <= N; i++) {
			sort(tree[i].begin(), tree[i].end());
		}
		bfs();
		connectParent();
		visit_order();
		int u = 1;
		while (!qq.empty()) {
			int v = qq.front();
			qq.pop();
			int p = LCA(u, v);
			ans += depth[u] - depth[p];
			ans += depth[v] - depth[p];
			u = v;
		}
		printf("#%d %lld\n", i, ans);
		for (int i = 1; i <= N; i++) {
			tree[i].clear();
		}
	}
	return 0;
}