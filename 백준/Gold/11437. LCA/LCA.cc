#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> tree[50505]; 
int parent[50505][22]; // log2(10000) 18; ceil 적용 , parent[i][k] i의 2^k번째 부모의 정점번호 
int depth[50505]; //각 정점의 깊이, 루트는 0
const int MAX = 18;

void dfs(int now) {
	for (int next : tree[now]) {
		if (depth[next] == -1) { //비 방문 처리
			depth[next] = depth[now] + 1;
			parent[next][0] = now; //하위 노드의 부모는 now
			dfs(next);
		}
	}
}

//parent 배열 채우기
void makeParent() {
	for (int k = 0; k < MAX-1; k++) {
		for (int i = 1; i <= N; i++) {
			if (parent[i][k] != -1) {
				parent[i][k+1] = parent[parent[i][k]][k];
			}
		}
	}
}

int solve(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	int diff = depth[u] - depth[v]; // 깊이 차이

	//깊이 차이를 같게 만드는 u의 조상 노드 탐색
	//예를 들어 깊이가 11차이이면 이진수로 1011 이므로 bit 연산으로 올라간다. 
	for (int i = 0; diff != 0; i++) {
		if (diff % 2 == 1) { //만약 젤 오른쪽 비트가 1이라면 
			u = parent[u][i];
		}
		//diff = (diff >> 2);
		diff /= 2;
	}

	if (u != v) { //두 정점이 다르다면 높이 2^MAX-1, ... 1 순으로 시도 (껑충 껑충 뛰어감)
		for (int k = MAX - 1; k >= 0; k--) {
			if (parent[u][k] != -1 && parent[u][k] != parent[v][k]) { //u의 2^K번째 부모가 있고, u와 v의 2^K의 부모가 서로 다르면 
				u = parent[u][k]; //이동 시켜봄 
				v = parent[v][k];
			}
		}
		//마지막엔 두 정점 u,v 의 부모가 같으므로 한번 더 올림
		u = parent[u][0];
	}

	return u;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	memset(parent, -1, sizeof(parent));
	fill(depth, depth + N + 1, -1);
	depth[1] = 0;
	dfs(1);
	makeParent();

	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		cout << solve(u, v) << "\n";
	}

	return 0;
}