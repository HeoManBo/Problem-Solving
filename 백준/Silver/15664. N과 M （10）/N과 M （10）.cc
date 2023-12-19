#include<bits/stdc++.h>
using namespace std;

int N, M;
int arr[11];
bool chk[11];
set<vector<int>> s;

void go(int now, int cnt) {
	if (cnt == M) {
		int flag = true;
		vector<int> f;
		for (int i = 0; i < N; i++) {
			if (chk[i]) {
				f.push_back(arr[i]);
			}
		}

		if (flag && s.find(f) == s.end()) {
			for (int i : f) {
				cout << i << ' ';
			}
			cout << '\n';
			s.insert(f);
		}

	}

	for (int i = now; i < N; i++) {
		if (!chk[i]) {
			chk[i] = true;
			go(i + 1, cnt + 1);
			chk[i] = false;
		}
	}

}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	go(0, 0);

}