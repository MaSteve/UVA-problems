#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t;
	while (cin>>s>>t) {
		int j = 0;
		for (int i = 0; i < t.size() && j < s.size(); i++){
			if (t[i] == s[j]) j++;
		}
		cout << (j == s.size()? "Yes": "No") << endl;
	}
	return 0;
}