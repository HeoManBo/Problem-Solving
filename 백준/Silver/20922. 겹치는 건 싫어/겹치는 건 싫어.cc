#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int N, K;
int cnt[101'101];
int arr[202'202];

int main(void) {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int l = 1, r = 1;
	int ans = -1;
	while (r <= N) {
		if (cnt[arr[r]] < K) {
			cnt[arr[r]]++;
			++r;
			ans = max(ans, r - l);
		}
		else if (cnt[arr[r]] == K) {
			while (cnt[arr[r]] == K) {
				cnt[arr[l]]--;
				l++;
			}
			cnt[arr[r]]++;
			++r;
			ans = max(ans, r - l);
		}
	}
	cout << ans << '\n';
	return 0;
}