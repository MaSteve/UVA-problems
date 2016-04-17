#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<string, string> m;

int main() {
	int L, N;
	cin >> L >> N;
	while (L--) {
		string s, p;
		cin >> s >> p;
		m.insert(pair<string, string>(s, p));
	}
	while (N--) {
		string s;
		cin >> s;
		if (m.count(s)) cout << m[s] << endl;
		else {
			if ((!(s[s.length()-2] == 'a' || s[s.length()-2] == 'e' || s[s.length()-2] == 'i' || s[s.length()-2] == 'o' || s[s.length()-2] == 'u') && s[s.length()-1] == 'y') || s[s.length()-1] == 'o'|| s[s.length()-1] == 's' || s[s.length()-1] == 'x' || ((s[s.length()-2] == 's' || s[s.length()-2] == 'c') && s[s.length()-1] == 'h')) {
				if (s[s.length()-1] == 'y') s[s.length()-1] = 'i';
				s.append("es");
			} else s.append("s");
			cout << s << endl;
		}
	}

	return 0;
}