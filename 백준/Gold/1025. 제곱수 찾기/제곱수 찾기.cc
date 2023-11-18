#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int squa(int num) {
	int a = (int)sqrt(num);
	return num == a * a;
}

int main(void) {
	int N, M;
	cin >> N >> M;
	int arr[10][10], ans = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	//행 
	for (int i = 0; i < N; i++) {
		//열 
		for (int j = 0; j < M; j++) {
			for (int di = -N; di < N; di++) { //행 증감량 
				for (int dj = -M; dj < M; dj++) { 
					if (!di && !dj) continue;
					int r = i, c = j, num = 0;
					while (r >= 0 && c >= 0 && r < N && c < M) {
						num = (num * 10) + arr[r][c];
						r += di; c += dj;
						if (squa(num)) ans = max(ans, num);
					}
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}