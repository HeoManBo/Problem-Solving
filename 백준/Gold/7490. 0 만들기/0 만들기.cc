#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;
vector<string> ans;

void solve(string s, int n, int sum) {
	if (n == N+1) {
		if (sum == 0) {
			ans.push_back(s.substr(1));
		}
		return;
	}

	//더하기
	solve(s + "+" + to_string(n), n + 1, sum + n);
	// * 10 더하기
	if (n <= N - 1) solve(s + "+" + to_string(n) + " " + to_string(n + 1), n + 2, sum + (n * 10 + (n + 1)));

	if (n == 1) return;

	//빼기
	solve(s + "-" + to_string(n), n + 1, sum - n);
	if (n <= N - 1) solve(s + "-" + to_string(n) + " " + to_string(n + 1), n + 2, sum - (n * 10 + (n + 1)));


}


int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		vector<string> expr;
		cin >> N;
		solve("", 1, 0);
		sort(ans.begin(), ans.end());
		for (string s : ans) {
			cout << s << '\n';
		}
		cout << '\n';
		ans.clear();
	}
}