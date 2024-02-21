#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5 * 3 + 3;

vector<int> tree[MAX];
long long depth[MAX], child[MAX]; // depth[i] : i 노드의 깊이, child[i] i노드의 자식 갯수
long long dnum, gnum, N;

long long comb(int n, int r);

void counting(int now, int parent, int d) {
	depth[now] = d;
	for (int next : tree[now]) {
		if (next != parent) {
			child[now]++;
			counting(next, now, d + 1);
		}
	}
}

void countingTree(int now, int parent) {
	if (depth[now] >= 4) {
		dnum++; 
	}
	for (int next : tree[now]) {
		if (next != parent) {
			dnum += (child[now] - 1) * child[next];
			gnum += comb(child[next], 2);
			countingTree(next, now);
		}
	}
	gnum += comb(child[now], 3); //현재 자식에서 3개 뽑음 
}

long long comb(int n, int r) {
	if (n < r) return 0;  
	long long result = 1;
	// n! / (n-r)! 계산
	for (long long i = 0; i < r; i++) {
		result *= (n - i);
	}

	for (long long i = r; i >= 1; i--) { // result / r! 계산 
		result /= i;
	}

	return result;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	counting(1, 0, 1);
	countingTree(1, 0);

	if (dnum > 3 * gnum) {
		cout << "D\n";
	}
	else if (dnum < 3 * gnum) {
		cout << "G\n";
	}
	else {
		cout << "DUDUDUNGA\n";
	}
	return 0;
}