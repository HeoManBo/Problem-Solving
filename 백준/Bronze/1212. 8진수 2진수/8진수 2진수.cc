#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

string eightToTwo[] = { "000", "001", "010", "011", "100", "101", "110", "111" }; //각 자리수를 2진수로 치환 

int main(void)
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int idx = s[i] - '0'; //변환할 8진수
		if (i == 0) cout << stoi(eightToTwo[idx]); //맨 앞의 0 제거
		else cout << eightToTwo[idx];
	}

	return 0; 
}