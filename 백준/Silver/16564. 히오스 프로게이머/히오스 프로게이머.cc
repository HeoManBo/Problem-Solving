#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>


using namespace std;

int N, K;
int level[1111111];

// 목표레벨 T에 도달이 가능한지 검사함
bool valid(int T) {
	int sum = K;
	for (int i = 1; i <= N; i++) {
		if (level[i] < T) {
			sum -= (T - level[i]); // 부족한만큼 레벨업
		}
		if (sum < 0) {
			return false; //불가능 
		}
	}

	return true;
}

int main(void)
{
	cin >> N >> K;
	int maxLevel = -1;
	for (int i = 1; i <= N; i++) {
		cin >> level[i];
		maxLevel = max(maxLevel, level[i]);
	}

	long l = 1, r = maxLevel + K; 
	long ans = 0;
	while (l <= r) {
		long mid = (l + r) / 2;
		if (valid(mid)) { //가능하면 목표 레벨을 올려봄
			ans = mid;
			l = mid + 1;
		}
		else { //불가능하면 목표 레벨을 낮춤
			r = mid - 1;
		}
	}
	

	cout << ans << '\n';
	return 0;
}
