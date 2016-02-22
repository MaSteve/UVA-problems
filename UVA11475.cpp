#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	while (cin >> word) {
		int j = word.length() - 1, match = 0;
		for (int i = 0; i < j; i++) {
			if (word[i] == word[j]) j--;
			else  i = match, j = word.length() - 1, match++;
		}
		cout << word;
		for (int i = match - 1; i >= 0; i--) cout << word[i];
		cout << endl;
	}
	return 0;
}