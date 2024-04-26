#include<bits/stdc++.h>

using namespace std;

int dp[101][101][101];

int main(void) {
	string s1, s2, s3;
	cin >> s1;
	cin >> s2;
	cin >> s3;

	for (int i = 1; i <= s3.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			for (int k = 1; k <= s1.size(); k++) {
				if (s3[i - 1] == s2[j - 1]  && s2[j-1] == s1[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
	}
	
	cout << dp[s3.size()][s2.size()][s1.size()] << "\n";

	return 0;
}