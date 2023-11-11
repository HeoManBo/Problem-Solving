#include<iostream>
#include<queue>
#include<string>
using namespace std;

int dayOfMonth[] = { -31, 31,28,31,30,31,30,31,31,30,31,30,31 };


int main(void) {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		string s;
		cin >> s;
		string year = s.substr(0, 4);
		string month = s.substr(4, 2);
		string day = s.substr(6, 2);
		int mm = stoi(month);
		int dd = stoi(day);
		if (dd < 1 || dd > dayOfMonth[mm]) {
			printf("#%d -1\n", i);
		}
		else {
			cout << '#'  << i << ' ' << year << '/' << month << '/' << day << '\n';
		}
	}
	return 0;
}