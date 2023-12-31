#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int ans = 0;
	int idx = 0;
	while (idx < s.size()) {
		if (s[idx] == 'c') {
			if (s[idx + 1] == '=') {
				idx++;
			}
			else if (s[idx + 1] == '-') {
				idx++;
			}
		}
		else if (s[idx] == 'd') {
			if (s[idx + 1] == 'z' && s[idx + 2] == '=') {
				idx += 2;
			}
			else if (s[idx + 1] == '-') {
				idx++;
			}
		}
		else if (s[idx] == 'l') {
			if (s[idx + 1] == 'j') {
				idx++;
			}
		}
		else if (s[idx] == 'n') {
			if (s[idx + 1] == 'j') {
				idx++;
			}
		}
		else if (s[idx] == 's') {
			if (s[idx + 1] == '=') {
				idx++;
			}
		}
		else if (s[idx] == 'z') {
			if (s[idx + 1] == '=') {
				idx++;
			}
		}
		idx++;
		ans++;
	}
	cout << ans << '\n';

	return 0;
}