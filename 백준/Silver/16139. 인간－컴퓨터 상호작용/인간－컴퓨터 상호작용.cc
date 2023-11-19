#include<bits/stdc++.h>
using namespace std;

int sum[26][201010];
string s;

int main(void) {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			sum[j][i] = (i == 0) ? 0 : sum[j][i - 1];
		}
		sum[s[i] - 'a'][i]++;
	}
	int q; cin >> q;
	while (q--) {
		char c; int l, r;
		cin >> c >> l >> r;
		int ans = (l == 0) ? sum[c - 'a'][r] : sum[c - 'a'][r] - sum[c - 'a'][l - 1];
		cout << ans << "\n";
	}
	return 0;
}