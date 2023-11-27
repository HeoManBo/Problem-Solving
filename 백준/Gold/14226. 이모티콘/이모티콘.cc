#include<bits/stdc++.h>

using namespace std;

int S; // dp[i][j] : i번째 이모티콘에서 j번째 연산을 했을 때 얻을 수 있는 최소 계산값

int chk[3333][3333];

int main(void)
{
	cin >> S;

	queue<pair<int,int>> q;
	q.push({ 1,0 });
	chk[1][0] = 0;
	int ans = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int clip = q.front().second; //클립 보드에 있는 복사 수
		q.pop();
		if (cur == S) {
			ans = chk[cur][clip];
			break;
		}
		//1. 복사하기
		if (!chk[cur][cur]) {
			q.push({ cur, cur });
			chk[cur][cur] = chk[cur][clip] + 1;
		}
		//2. 모든 화면에 붙여넣기
		if ((cur+clip <= 2222) && !chk[cur + clip][clip]) {
			q.push({ cur + clip, clip });
			chk[cur+clip][clip] = chk[cur][clip] + 1;
		}
		//3. 이모티콘 중 하나 삭제
		if (cur > 0 && !chk[cur - 1][clip]) {
			q.push({ cur - 1, clip });
			chk[cur - 1][clip] = chk[cur][clip] + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}