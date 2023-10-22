#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<pair<long long, long long>> tree;
long long ans;

int cmp(pair<long long, long long> a, pair<long long, long long> b) {
	return a.first < b.first;
}

int main(void)
{
	cin >> N;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> tree[i].second;
	}
	for (int i = 0; i < N; i++) {
		cin >> tree[i].first;
	}
	sort(tree.begin(), tree.end(), cmp); // 조금씩 자라는 놈들부터 먼저 자르기
	for (int i = 0; i < N; i++) {
		ans += tree[i].second + tree[i].first * i;
	}

	cout << ans << "\n";

	return 0;
}