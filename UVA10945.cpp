#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool isnotalpha(char c) {
	return !isalpha(c);
}

void proc(string & word, bool & pal) {
	for (int i = 0, j = word.length() - 1; i <= j; i++, j--) {
		if (word[i] != word[j]) pal = false;
	}
}

int main() {
	string word;
	while (getline(cin, word) && word != "DONE") {
		bool pal = true;
		word.erase(remove_if(word.begin(), word.end(), isnotalpha), word.end());
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		proc(word, pal);
		if(pal) cout << "You won't be eaten!";
		else cout << "Uh oh..";
		cout << endl;
	}
	return 0;
}