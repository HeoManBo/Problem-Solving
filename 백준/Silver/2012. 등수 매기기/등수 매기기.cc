#include<bits/stdc++.h>

using namespace std;

int arr[505'505];

int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	sort(arr+1, arr + N+1); //예상 등수 정렬
	long long ans = 0;
	for (int i = 1; i <= N; i++) {  //i는 실제 등수, -> arr[i]는 예상 등수 -> 의 차이
		ans += abs(arr[i] - i);
	}
	cout << ans << '\n';
	return 0;
}