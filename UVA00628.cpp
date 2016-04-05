#include <iostream>
#include <vector>
using namespace std;

vector<string> dict;
string pattern;
vector<string> sol;
string num[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void proc(int pos) {
	if (pos == pattern.length()) {
		for (int i = 0; i < pos; i++) {
			cout << sol[i];
		}
		cout << endl;
	} else {
		if (pattern[pos] == '0') {
			for (int i = 0; i < 10; i++) {
				sol[pos] = num[i];
				proc(pos+1);
			}
		} if (pattern[pos] == '#') {
			for (int i = 0; i < dict.size(); i++) {
				sol[pos] = dict[i];
				proc(pos+1);
			}
		}
	}
}

int main() {
	int n, m;
	while (cin >> n) {
		dict.clear();
		while (n--) {
			string word;
			cin >> word;
			dict.push_back(word);
		}
		cin >> m;
		cout << "--" << endl;
		while (m--) {
			cin >> pattern;
			sol.assign(pattern.length(), "");
			proc(0);
		}
	}
	return 0;
}