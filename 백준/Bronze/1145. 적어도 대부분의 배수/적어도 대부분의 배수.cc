#include<bits/stdc++.h>
using namespace std;

int arr[5];

int main(void)
{
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	int can = 1;
	while (true) {
		int count = 0;
		for (int i = 0; i < 5; i++) {
			if ((can % arr[i]) == 0) {
				count++;
			}
		}
		if (count >= 3) {
			cout << can << '\n';
			break;
		}
		can++;
	}
	return 0;
}