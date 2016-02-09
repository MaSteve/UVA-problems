#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int proc(string expression, bool & ok) {
	if (expression.length() == 0) {
		ok = false;
		return 0;
	} 
	int val = 0, op1, fact, j;
	bool empty = true, op = false;
	for (int i = 0; i < expression.length(); i++) {
		if(isdigit(expression[i])) {
			j = 1;
			for (; j+i < expression.length() && isdigit(expression[j+i]); j++);
			fact = atoi((expression.substr(i, j)).c_str());
			j--;
		} else if(expression[i] == '(') {
			int open = 0;
			j = 1;
			for (; j+i < expression.length() && !(expression[j+i] == ')' && open == 0); j++) {
				if (expression[j+i] == '(') open++;
				else if (expression[j+i] == ')') open--;
			}
			fact = proc(expression.substr(i+1, j-1), ok);
		} else {
			ok = false; 
			break; 
		}
		if (!op) op1 = fact;
		else op1 *= fact;
		i += j + 1;
		if (i < expression.length()) {
			if (expression[i] == '+') val += op1, op = false;
			else if (expression[i] == '*') op = true;
			else {
				ok = false; 
				break;
			}
			if (i + 1 >= expression.length()) ok = false;
		} else val += op1;
	}
	return val;
}

int main() {
	int N;
	string expression;
	cin >> N;
	getline(cin, expression);
	while (N--) {
		getline(cin, expression);
		bool ok = true;
		int res = proc(expression, ok);
		if (ok) cout << res << endl;
		else cout << "ERROR" << endl;
	}
	return 0;
}