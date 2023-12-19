#include<bits/stdc++.h>
using namespace std;

int N;
int arr[1'000'001];

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> lis;
	lis.push_back(-1);
	int length = 0;
	for (int i = 0; i < N; i++) {
		if (lis.back() < arr[i]) {
			lis.push_back(arr[i]);
			length++;
		}
		else if(lis.back() > arr[i]){
			auto it = lower_bound(lis.begin() + 1, lis.end(), arr[i]);
			*it = arr[i];
		}
	}

	cout << length << '\n';

	return 0;
}