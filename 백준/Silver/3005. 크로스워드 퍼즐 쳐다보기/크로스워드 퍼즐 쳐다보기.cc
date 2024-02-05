#include<bits/stdc++.h>
using namespace std;

int R, C;
int presentAlphabet[26];
string input[22];
string MAX_STRING = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
string emptyString = "";

string getRow(int y, int x) {
	if (x > 0 && input[y][x - 1] != '#') return MAX_STRING; //중간에 있는 단어는 제외

	string result = emptyString + input[y][x++];
	while (x < C && input[y][x] != '#') {
		result += input[y][x++];
	}

	return result.size() >= 2 ? result : MAX_STRING;
}

string getColumn(int y, int x) {
	if (y > 0 && input[y - 1][x] != '#') return MAX_STRING; //중간에 있는 단어는 제외 

	string result = emptyString + input[y++][x];
	while (y < R && input[y][x] != '#') {
		result += input[y++][x];
	}

	return result.size() >= 2 ? result : MAX_STRING;
}

int main(void)
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> input[i];
		for (int j = 0; j < C; j++) {
			if (input[i][j] == '#') continue;
			presentAlphabet[input[i][j] - 'a']++; //board에 존재하는 알파벳 갯수
		}
	}

	string ans = MAX_STRING;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (input[i][j] == '#' || presentAlphabet[input[i][j] - 'a'] == 0) continue;
			string x_axis = getRow(i, j);
			string y_axis = getColumn(i, j);
			string tmp = x_axis > y_axis ? y_axis : x_axis;
			ans = ans > tmp ? tmp : ans;
		}
	}

	cout << ans << '\n';
	return 0;
}