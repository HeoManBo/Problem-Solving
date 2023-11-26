#include<bits/stdc++.h>
#define MALE 1
#define FEMALE 2
using namespace std;

int N, arr[111];

void male(int init) {
	for (int i = init; i <= N; i += init) {
		arr[i] = !arr[i];
	}
}

void female(int init) {
	int l = init;
	int r = init;
	while (l >= 1 && r <= N) {
		l--;
		r++;
		if (arr[l] != arr[r]) {
			break;
		}
	}
	for (int i = l + 1; i <= r - 1; i++) {
		arr[i] = !arr[i];
	}
	
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int sex, num; cin >> sex >> num; 
		if (sex == MALE) {
			male(num);
		}
		else {
			female(num);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << ' ';
		if ((i % 20 == 0) && (i != N)) cout << '\n';
	}
	cout << '\n';
	return 0;
}