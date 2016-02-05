#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int var[30];

bool proc(string str) {
	for (int i = 0; i < 30; i++) var[i] = -1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '&') continue;
		if (str[i] == '~') {
			i++;
			if (var[str[i]-'a'] == -1) var[str[i]-'a'] = 0;
			else if (var[str[i]-'a'] == 1) return false;
		} else {
			if (var[str[i]-'a'] == -1) var[str[i]-'a'] = 1;
			else if (var[str[i]-'a'] == 0) return false;
		}
	}
	return true;
}

int main() {
	int T;
	string form;
	cin >> T;
	while (T--){
		cin >> form;
		bool ok = false;
		int last;
		for (int i = 0; i < form.length() && !ok; i++) {
			if (form[i] == '(') last = i;
			else if (form[i] == ')') ok = ok || proc(form.substr(last+1, i-last-1));
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}