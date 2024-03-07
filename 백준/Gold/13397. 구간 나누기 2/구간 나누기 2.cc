#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[5050];

// 각 그룹에 가질 수 있는 최댓값이 X 일 때 몇개의 그룹을 만들 수 있을까?
bool valid(int x) {
	int cnt = 0;
	int MIN = arr[0], MAX = arr[0];
	for (int i = 0; i < N; i++) {
		MIN = min(MIN, arr[i]);
		MAX = max(MAX, arr[i]);
		if ((MAX - MIN) > x) { //만약 해당 그룹에 최댓값이 X d
			cnt++;
			MIN = arr[i];
			MAX = arr[i];
		}
	}

	return cnt >= M;
}

int main(void) {
	cin >> N >> M;
	int MIN = 12345689;
	int MAX = -1;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		MIN = min(MIN, arr[i]);
		MAX = max(MAX, arr[i]);
	}
	int l = 0;
	int r = MAX - MIN;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (valid(mid)) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << l << '\n';
	return 0;
}