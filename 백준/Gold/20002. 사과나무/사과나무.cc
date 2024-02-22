#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;


int N, ans = -987654321;
int arr[333][333];

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			ans = max(ans, arr[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		arr[0][i] += arr[0][i - 1];
		arr[i][0] += arr[i - 1][0];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) { //K 한 변의 길이가 K인 정사각형의 넓이 
				if (i + k > N || j + k > N) continue;
				ans = max(ans, arr[i + k][j + k] - arr[i + k][j-1] - arr[i-1][j + k] + arr[i-1][j-1]);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
