#include<bits/stdc++.h>

using namespace std;

string s, t;

int main(void)
{
	cin >> s >> t;
	string ss = "";
	string tt = "";

	for (int i = 0; i < t.length(); i++) {
		ss += s;
	}
	for (int j = 0; j < s.length(); j++) {
		tt += t;
	}

	if (ss == tt) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}

	return 0;
}