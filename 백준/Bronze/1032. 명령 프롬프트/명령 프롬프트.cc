#include<bits/stdc++.h>
using namespace std;


int main(void)
{
	int N;
	cin >> N;
	vector<string> s;
	for (int i = 0; i < N; i++) {
		string ss;
		cin >> ss;
		s.push_back(ss);
	}

	for (int i = 0; i < s[0].size(); i++) {
		char st = s[0][i];
		for (int j = 1; j < s.size(); j++) {
			if (st != s[j][i]) {
				st = '?';
				break;
			}
		}
		cout << st;
	}
	cout << '\n';
	return 0;
}