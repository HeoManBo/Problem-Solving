#include<bits/stdc++.h>

using namespace std;

int N;
set<string> s;

int cmp(string& a, string& b) {
	if (a.length() == b.length()) {
		return a < b;
	}

	return a.length() < b.length();
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		string ss;
		cin >> ss;
		if (s.find(ss) == s.end()) {
			s.insert(ss);
		}
	}

	vector<string> remove; 
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		remove.push_back(*iter);
	}

	sort(remove.begin(), remove.end(), cmp);

	for (string ss : remove) {
		cout << ss << '\n';
	}

	return 0;
}