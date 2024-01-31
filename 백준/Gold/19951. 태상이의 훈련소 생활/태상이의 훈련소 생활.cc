#include<bits/stdc++.h>
using namespace std;

int N, M;
int arr[101010], delta[101010];

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++) {
		int a, b, k;
		cin >> a >> b >> k;
		delta[a] += k;
		delta[b + 1] += -k;
	}
	for (int i = 1; i <= N; i++) {
		delta[i] += delta[i - 1];
		arr[i] += delta[i];
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}