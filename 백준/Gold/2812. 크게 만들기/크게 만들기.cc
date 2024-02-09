#include<bits/stdc++.h>

using namespace std;

int arr[555'555];


int main(void)
{
	int N, K;
	cin >> N >> K;
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%1d", arr + i);
	}

	stack<int> st;
	
	for (int i = 0; i < N; i++) {
		while (!st.empty() && st.top() < arr[i] && K ) {
			K--;
			st.pop();
		}
		st.push(arr[i]);
	}

	while (K) {
		st.pop();
		K--;
	}

	string s = "";

	while (!st.empty()) {
		int now = st.top();
		st.pop();
		s.append(to_string(now));
	}
	reverse(s.begin(), s.end());

	cout << s << '\n';
	return 0;
}