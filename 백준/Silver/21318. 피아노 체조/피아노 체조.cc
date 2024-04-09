#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, Q;
int ackbo[101'101], presum[101'101];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ackbo[i];
		if (ackbo[i - 1] > ackbo[i]) {
			presum[i]++;
		}
		presum[i] += presum[i - 1];
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		cout << presum[b] - presum[a] << '\n';
	}

	return 0;
}