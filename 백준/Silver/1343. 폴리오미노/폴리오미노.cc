#include<iostream>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int cnt = 0;
		if (s[i] == '.') continue;
		for (int st = i; st < i + 4 && st < s.size(); st++) {
			if (s[st] == '.') {
				break;
			}
			cnt++;
		}
		if (cnt == 2) {
			s[i] = s[i + 1] = 'B';
			i += 1;
		}
		else if (cnt == 4) {
			s[i] = s[i + 1] = s[i + 2] = s[i + 3] = 'A';
			i += 3;
		}
		else {
			cout << "-1\n";
			return 0;
		}
	}
	cout << s << '\n';

	return 0;
}