#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;

vector<char> st;
string input;
string boom;
int main(void) {
	cin >> input;
	cin >> boom;
	int flag = 1;
	for (int i = 0; i < input.length(); i++) {
		st.push_back(input[i]);
		flag = 1;
		if (st.size() >= boom.length()) {
			for (int i = 0; i < boom.length(); i++) {
				if (st[st.size() - boom.length() + i] != boom[i]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				for (int i = 0; i < boom.length(); i++) {
					st.pop_back();
				}
			}
		}
	}

	if (st.empty()) {
		cout << "FRULA" << "\n";
	}
	else {
		for (char i : st) {
			cout << i;
		}
		cout << "\n";
	}
}