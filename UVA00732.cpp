#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string s1, s2;
vector<bool> v;
stack<char> s;

void func (int pos1, int pos2, int posv){
	if (pos2 == s2.length()) {
		bool first = false;
		for (int i = 0; i < v.size(); i++) {
			if (first) cout << " ";
			else first = true;
			cout << (v[i]? "i": "o");
		}
		cout << endl;
	}
	else {
		if (pos1 < s1.size()) {
			s.push(s1[pos1]);
			v[posv] = true;
			func(pos1+1, pos2, posv+1);
			s.pop();
		}
		if (!s.empty() && s.top() == s2[pos2]) {
			s.pop();
			v[posv] = false;
			func(pos1, pos2+1, posv+1);
			s.push(s2[pos2]);
		}
	}
}

int main() {
	while (getline(cin, s1) && getline(cin, s2)) {
		cout << "[" << endl;
		if (s1.length() == s2.length()) {
			v.assign(2*s1.length(), false);
			func(0, 0, 0);
		}
		cout << "]" << endl;
	}
	return 0;
}