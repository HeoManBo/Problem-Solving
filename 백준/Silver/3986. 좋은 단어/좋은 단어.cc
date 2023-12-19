#include<bits/stdc++.h>
using namespace std;

int N;

int main(void)
{
	cin >> N;
	int ans = 0;

	while (N--) {
		string s; 
		cin >> s;
		stack<char> st;

		for (int i = 0; i < s.size(); i++) {
			if (st.empty()) {
				st.push(s[i]);
			}
			else {
				if (st.top() == s[i]) {
					st.pop();
				}
				else {
					st.push(s[i]);
				}
			}
		}
		if (st.empty()) ans++;
	}
	cout << ans << '\n';

	return 0;
}