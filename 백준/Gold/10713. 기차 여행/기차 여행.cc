#include<bits/stdc++.h>
using namespace std;

struct cost {
	int ticket; //티켓 값
	int ic_card; //IC 카드 이용시 통행료
	int ic_buy; //IC 카드 값 
};

int N, M;
int path[101010]; 
long long delta[101010] ; // i번 철도길을 몇 번 이용하는지
cost c[101010];
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> path[i];
	}

	for (int i = 1; i < N; i++) {
		cin >> c[i].ticket >> c[i].ic_card >> c[i].ic_buy;
	}

	for (int i = 0; i < M - 1; i++) { // day[i-1]--> 누적합 
		//i일 
		int from = path[i]; //출발지 
		int to = path[i + 1]; //도착지 

		if (from < to) {
			delta[from]++;
			delta[to]--;
		}
		else {
			delta[to]++;
			delta[from]--;
		}
		
	}

	for (int i = 1; i <= N; i++) {
		delta[i] += delta[i - 1];
	}

	long long ans = 0;
	// i번째 도시를 k번 간다고 했을 때 해당 도시를 가장 저렴하게 가는법
	// min (ai*k, bi*k + ci); 
	for (int i = 1; i < N; i++) {
		ans += min((long long)delta[i] * c[i].ticket, (long long)delta[i] * c[i].ic_card + c[i].ic_buy);
	}

	cout << ans << '\n';
	return 0;
}
