#include<bits/stdc++.h>

using namespace std;

#define ll long long

int N, M;
ll arr[1'000'001];
ll mod[1111];

int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
		mod[arr[i] % M]++;
	}

	ll ans = 0;
	ans += mod[0];
	for (int i = 0; i < M; i++) {
		ans += (mod[i] * (mod[i] - 1)) / 2;
	}

	cout << ans << '\n';

	return 0;
}