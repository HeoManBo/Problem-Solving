#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<cmath>

using namespace std;

int N, M;
vector<int> arr[32001];
int inDegree[32001];
int result[32001];

void solve() {
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			pq.push(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (pq.empty()) {
			break;
		}
		int x = pq.top();
		pq.pop();
		result[i] = x;
		for (int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i];
			if (--inDegree[y] == 0) {
				pq.push(y);
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	int front, back;
	for (int i = 0; i < M; i++) {
		cin >> front >> back;
		arr[front].push_back(back);
		inDegree[back]++;
	}
	solve();
	for (int i = 1; i <= N; i++) {
		cout << result[i] << " ";
	}
	return 0;
}