#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, L, R, X;
int arr[1515];
int ans;

vector<int> l; //문제 list
bool chk[10101];


void print() {
	//문제 리스트 출력
	for (int i : l) {
		cout << i << " ";
	}
	cout << "\n";
}

void solve(int cnt, int idx, int sum) {
	if (cnt >= 2) { //고른 문제가 2개 이상이라면
		int min_x = 987654321;
		int max_x = -987654321;
		int s = 0;

		for (int i = 0; i < l.size(); i++) {
			s += l[i];
			min_x = min(min_x, l[i]);
			max_x = max(max_x, l[i]);
		}
		if (s >= L && s <= R && max_x - min_x >= X) {
			//print();
			ans++;
		}

	}

	for (int i = idx; i <= N; i++) {
		if (chk[i]) continue;
		if (sum + arr[i] <= R) { 
			chk[i] = true;
			l.push_back(arr[i]);
			solve(cnt + 1, i, sum + arr[i]);
			l.pop_back();
			chk[i] = false;
		}
	}
}

int main(void) {
	cin >> N >> L >> R >> X;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	solve(0, 1, 0);
	cout << ans << "\n";
	return 0;
}