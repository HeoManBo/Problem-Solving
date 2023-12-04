#include<bits/stdc++.h>

using namespace std;

#define ll long long

int N, M, K;
int arr[22][22];
vector<pair<int, int>> q;
bool chk[22][22];
int ans = -987654321;


bool canPush(int y, int x) {
	//후보 점에서 동,서,남,북 했을 때 겹치는 점이 있으면 안됨.
	for (pair<int, int> cand : q) {
		int yy = cand.first;
		int xx = cand.second;
		if (yy + 1 == y && xx == x) return false; //남
		if (yy - 1 == y && xx == x) return false; //북
		if (xx + 1 == x && yy == y) return false; //동
		if (xx - 1 == x && yy == y) return false; //서
	}
	return true;
}

void go(int count, int sum) {
	if (count == K) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!chk[i][j] && canPush(i,j)) {
				chk[i][j] = true;
				q.push_back({ i,j });
				go(count + 1, sum + arr[i][j]);
				q.pop_back();
				chk[i][j] = false;
			}
		}
	}

}

int main(void) {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	go(0, 0);
	cout << ans << '\n';

	return 0;
}