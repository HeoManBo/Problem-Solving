#include<bits/stdc++.h>
using namespace std;

int N, L, R, X;
int arr[22], ans, chk[22];

void solve(int idx, int cnt, vector<int>& list) {
	if (cnt >= 2) {
		int MIN = 0x3f3f3f3f;
		int MAX = -0x3f3f3f3f;
		int sum=0;

		for (int i : list) {
			MIN = min(MIN, i);
			MAX = max(MAX, i);
			sum += i;
		}

		if (sum >= L && sum <= R && (MAX - MIN) >= X) {
			ans++;
		}
	}

	for (int i = idx; i <= N; i++) {
		if (!chk[i]) {
			chk[i] = true;
			list.push_back(arr[i]);
			solve(i + 1, cnt + 1, list);
			list.pop_back();
			chk[i] = false;
		}
	}

}

int main(void)
{
	cin >> N >> L >> R >> X;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	vector<int> list;
	solve(1, 0, list);
	cout << ans << '\n';
	return 0;
}