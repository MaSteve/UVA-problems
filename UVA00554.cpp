#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;

int main() {
	string s;
	unordered_set<string> dict;
	while (cin >> s && s != "#") dict.insert(s);
	getline(cin, s);
	getline(cin, s);
	stringstream ss;
	int max = -1;
	string msg;
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < s.length(); j++) s[j] = s[j] == ' '? 'A': s[j] == 'Z'? ' ': s[j] + 1;
		int match = 0;
		for (int j = 0; j < s.length(); j++) {
			if(s[j] == ' ') {
				if (dict.count(ss.str())) match++;
				ss.str("");
			} else ss << s[j];
		}
		if (dict.count(ss.str())) match++;
		ss.str("");
		if (match > max) msg = s, max = match;
	}
	int count = 0;
	string esp = "";
	for (int j = 0; j < msg.length(); j++) {
			if(msg[j] == ' ') {
				if (count + ss.str().length() + esp.length() > 60) cout << endl, esp = "", count = 0;
				cout << esp << ss.str();
				count += ss.str().length() + esp.length();
				esp = " ";
				ss.str("");
			} else ss << msg[j];
	}
	cout << endl;
	return 0;
}