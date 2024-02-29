#include<bits/stdc++.h>

using namespace std;

int N, happiness[1'000'111], sadness[1'000'111];
int youth[1'000'001][2], old[1'000'001][2];
const int INF = 0x3f3f3f3f;


// 임의의 젊은 날의 행복도는 임의의 늙은 날의 행복도보다 높다. : 즉 젊은 날의 최소 행복도는 늙은 날의 최대 행복도보다 높다 
// 임의의 젊은 날의 피로도는 임의의 늙은 날의 피로도보다 낮다. : 즉 젊은 날의 최대 피로도는 늙은 날의 최소 피로도보다 낮다. 


int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> happiness[i] >> sadness[i];
	}

	int maxHappy = -1, minHappy = INF;
	int maxSad = -1, minSad = INF;
	

	//젊은날
	for (int i = 1; i <= N; i++) {
		if (happiness[i] != 0 && happiness[i] < minHappy) {
			minHappy = happiness[i];
		}
		if (sadness[i] != 0 && sadness[i] > maxSad) {
			maxSad = sadness[i];
		}
		//i날의 최소 행복, 최대 불행
		youth[i][0] = minHappy;
		youth[i][1] = maxSad;
	}

	//늙은 날
	for (int i = N; i >= 1; i--) {
		if (happiness[i] != 0 && happiness[i] > maxHappy) {
			maxHappy = happiness[i];
		}
		if (sadness[i] != 0 && sadness[i] < minSad) {
			minSad = sadness[i];
		}
		old[i][0] = maxHappy;
		old[i][1] = minSad;
	}


	// K를 찾자
	// K는 젊은날이며 K+1부터는 늙은날.
	// 즉 K날 까지의 젊은날의 최소 행복도가 K+1 이후의 최대 행복도보다 커야하며
	// K 날까지의 젊은날의 최대 피로도가 K+1 이후의 최소 피로도보다 작은 날의 K를 발견하면 break;
	int K = -1;
	for (int k = N-1; k >= 0; k--) {
		if (youth[k][0] > old[k+1][0] && youth[k][1] < old[k+1][1]) {
			K = k;
			break;
		}
	}	

	cout << K << '\n';

	return 0;
}