#include<iostream>
#include<string>
#include<map>
using namespace std;

string s;
int ans = -1;


void dfs(int idx, int swap_count) {
	if (swap_count == 0) {
		ans = max(ans, stoi(s));
		return;
	}

	for (int i = idx; i < s.length(); i++) {
		for (int j = i + 1; j < s.length(); j++) {
			swap(s[i], s[j]);
			dfs(i, swap_count - 1);
			swap(s[i], s[j]);
		}
	}
}

int main(void) {
	int N;
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		ans = -1;
		int K;
		cin >> s >> K;
		if (s.length() < K) {
			K = s.length();
		}
		dfs(0, K);
		printf("#%d %d\n", i, ans);
	}
	return 0;
}