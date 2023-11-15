#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int TC, N, M;
vector<string> isPelin;
vector<string> notPelin;

string rev_string(string& s) {
	string ss;
	for (int i = s.size() - 1; i >= 0; i--) {
		ss += s[i];
	}

	return ss;
}


int main(void)
{
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			if (s == rev_string(s)) { //펠린드롬이면 
				isPelin.push_back(s);
			}
			else {
				notPelin.push_back(s);
			}
		}

		int cnt = 0;
		while (notPelin.size() != 0) {
			string s = notPelin[notPelin.size()-1];
			notPelin.pop_back();
			if (find(notPelin.begin(), notPelin.end(), rev_string(s)) != notPelin.end()) {
				cnt += 2;
			}
		}

		int ans = cnt * M;
		if (isPelin.size() != 0) {
			ans += M;
		}

		printf("#%d %d\n", tc, ans);
		isPelin.clear();
		notPelin.clear();
	}

}