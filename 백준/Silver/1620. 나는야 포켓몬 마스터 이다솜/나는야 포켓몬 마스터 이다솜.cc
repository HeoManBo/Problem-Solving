#include<bits/stdc++.h>

using namespace std;

map<string, int> strToInt;
map<int, string> intToStr;
int number = 1, N, M;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		strToInt[s] = number;
		intToStr[number++] = s;
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s; 
		if (strToInt.find(s) == strToInt.end()) {
			cout << intToStr[stoi(s)] << '\n';
		}
		else {
			cout << strToInt[s] << '\n';
		}
	}

	return 0;
}