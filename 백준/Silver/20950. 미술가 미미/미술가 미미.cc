#include<bits/stdc++.h>

using namespace std;

int N;
int color[33][3];
int gom[3];
bool selected[33]; //이번 회차에서 섞을 컬러들
int ans = 987654321;

//색 계산
int cal(int limit) {
	int rgb[3] = { 0, 0, 0 };

	for (int i = 0; i < N; i++) {
		if (selected[i]) {
			for (int j = 0; j < 3; j++) {
				rgb[j] += color[i][j];
			}
		}
	}
	rgb[0] /= limit;
	rgb[1] /= limit;
	rgb[2] /= limit;

	int gap = 0;
	for (int i = 0; i < 3; i++) {
		gap += abs(gom[i] - rgb[i]);
	}

	return gap;
}

void go(int now, int cnt, int limit) {
	if (cnt == limit) {
		int mix = cal(limit);
		ans = min(mix, ans);
		return;
	}

	for (int i = now; i < N; i++) {
		if (!selected[i]) { //현재 물감 선택
			selected[i] = true;
			go(i + 1, cnt + 1, limit);
			selected[i] = false;
		}
	}

}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
		}
	}
	cin >> gom[0] >> gom[1] >> gom[2];

	//30C7 -> 가능 
	for (int i = 2; i <= N; i++) { //최대 7개 선택
		if (i >= 8) break;
		go(0, 0, i);
	}

	cout << ans << '\n';
	return 0;
}