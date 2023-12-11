#include<iostream>
#include<vector>
using namespace std;

int N;
int oper[5];
vector<int> num;
int min_ans=987654321, max_ans = -987654321;


void go(int idx, int sum) {
	if (idx == N) {
		min_ans = min(sum, min_ans);
		max_ans = max(sum, max_ans);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i]) {
			oper[i]--;
			if (i == 0) {
				go(idx + 1, sum + num[idx]);
			}
			else if (i == 1) {
				go(idx + 1, sum - num[idx]);
			}
			else if (i == 2) {
				go(idx + 1, sum * num[idx]);
			}
			else {
				go(idx + 1, sum / num[idx]);
			}
			oper[i]++;
		}
	}

}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		num.push_back(n);
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	go(1, num[0]);

	cout << max_ans << '\n';
	cout << min_ans << '\n';
	return 0;
}