#include<bits/stdc++.h>
#include<sstream>
using namespace std;

int N;
stack<double> st;
string s;
double num[99];

double oper(char op, double a, double b) {
	if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else if (op == '*') {
		return a * b;
	}
	else {
		return a / b;
	}
}

int main(void)
{
	int N;
	cin >> N;
	cin >> s;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		num[i] = n * 1.0;
	}
	double ans = 0.0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			st.push(num[s[i] - 'A']);
		}
		else {
			double a = st.top(); st.pop();
			double b = st.top(); st.pop();
			st.push(oper(s[i], b, a));
		}
	}
	printf("%.2f\n", st.top());
	return 0;
}