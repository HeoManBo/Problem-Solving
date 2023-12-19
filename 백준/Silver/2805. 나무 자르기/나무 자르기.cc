#include<bits/stdc++.h>
using namespace std;

int N, M;
int tree[1010101];

int main(void)
{
	cin >> N >> M;
	int max_height = -1;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		max_height = max(max_height, tree[i]);
	}
	long long l = 0, r = max_height;
	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long size = 0; //mid 높이로 잘랐을 때 얻을수 있는 나무 양
		for (int i = 0; i < N; i++) {
			if ((tree[i] - mid) > 0) {
				size += tree[i] - mid;
			}
		}
		if (size >= M) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';

	return 0;
}