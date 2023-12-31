#include<bits/stdc++.h>
using namespace std;

int arr[1111][1111], N;

//(y,x)가 시작점이고, 크기가 N인 보드 -> 크기가 1 아닌 경우 경우 분할한다
int go(int y, int x, int size) {
	if (size <= 1 ) { //기저 케이스
		return arr[y][x];
	}
	else {
		vector<int> a;
		//4분할 수행
		int f = go(y, x, size / 2);
		int s = go(y, x + size / 2, size / 2);
		int t = go(y + size / 2, x, size / 2);
		int sa = go(y + size / 2, x + size / 2, size / 2);
		a.push_back(f);
		a.push_back(s);
		a.push_back(t);
		a.push_back(sa);
		sort(a.begin(), a.end());
		return a[1];	
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	cout << go(0, 0, N) << '\n';
	return 0;
}