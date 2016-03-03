#include <iostream>
#include <string>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string eq;
	int correct = 0;
	while (cin >> eq) {
		int a = 0, b = 0, c = 0, i = 0;
		bool op, na = false; // +/!-
		for (; i < eq.length(); i++) {
			if(eq[i] != '+' && eq[i] != '-') a = 10*a + (eq[i]-'0');
			else { op = eq[i] == '+'; break; }
		}
		i++;
		for (; i < eq.length(); i++) {
			if(eq[i] != '=') b = 10*b + (eq[i]-'0');
			else break;
		}
		i++;
		for (; i < eq.length(); i++) {
			if(eq[i] != '?') c = 10*c + (eq[i]-'0');
			else { na = true; break; }
		}
		if (!na) {
			if ((op && a + b == c) || (!op && a - b == c))  correct++;
		}
	}
	printf("%d\n", correct);
	return 0;
}