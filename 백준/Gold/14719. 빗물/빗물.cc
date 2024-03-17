#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int H, W, ans;
int height[555];
bool chk[555][555];

void solve(int l, int r) { // (l,r)구간에 물을 채운다.
	int m = min(height[l], height[r]); //채울 수 있는 최대 높이
	for (int i = l + 1; i < r; i++) {
		for (int j = height[i]; j < m; j++) {
			if (!chk[i][j]) {
				chk[i][j] = true;
				ans++;
			}
		}
	}
}

int main(void)
{
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		cin >> height[i];
	}
	

	//for (int i = 0; i < W; i++) {
	//	int l = height[i]; //왼쪽 벽의 높이
	//	for (int j = i + 1; j < W; j++) {
	//		int r = height[j]; //오른쪽 벽의 높이
	//		if (l != 0 && r != 0) { //두 벽의 높이가 0이 아니면
	//				solve(i, j);
	//		}
	//		if (l == r || l < r) {
	//			i = j - 1;
	//			break;
	//		}
	//	}
	//}

	// arr[x]를 기준으로 왼쪽의 최대 기둥 높이와 오른쪽의 최대 높이 기둥을 구함
	for (int i = 1; i < W-1; i++) {
		int l = 0, r = 0;
		for (int j = 0; j < i; j++) l = max(l, height[j]); // 
		for (int k = W - 1; k > i; k--) r = max(r, height[k]);
		ans += max(0, min(l, r) - height[i]);
	}


	cout << ans << '\n';
	return 0;
}