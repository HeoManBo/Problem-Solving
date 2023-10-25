#include<bits/stdc++.h>

using namespace std;


vector<pair<int, int>> money;
int n;
int dp[50505]; // i원일 때 나눌 수 있는가? 

int main(void) {
	for(int i=0; i<3; i++){
		money.clear();
		memset(dp, 0, sizeof(dp));
		int sum = 0; //전체 동전의 합
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			money.push_back({ a,b });
			sum += (a * b); 
		}
		//동전의 합이 홀수라면 절대 나눌 수 없음
		if (sum % 2) {
			cout << "0\n";
			continue;
		}
		else {
			dp[0] = 1; //기저 케이스
			for (int i = 0; i < money.size(); i++) {
				int cnt = money[i].second;
				int coin = money[i].first;
				for (int j = 50000; j >= 0; j--) {
					if (j - coin >= 0 && dp[j - coin]) {
						for (int k = 0; k < cnt; k++) {
							if (j + coin * k < 50001) {
								dp[j + coin * k] = 1;
							}
						}
					}
				}
			}
			cout << dp[sum / 2] << "\n";
		}
	}
}