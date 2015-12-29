#include <iostream>
#include <string>
using namespace std;

bool reverse(char a, char b) {
	switch (a) {
		case 'A': return b == 'A';
		case 'E': return b == '3';
		case 'H': return b == 'H';
		case 'I': return b == 'I';
		case 'J': return b == 'L';
		case 'L': return b == 'J';
		case 'M': return b == 'M';
		case 'O': return b == 'O';
		case 'S': return b == '2';
		case 'T': return b == 'T';
		case 'U': return b == 'U';
		case 'V': return b == 'V';
		case 'W': return b == 'W';
		case 'X': return b == 'X';
		case 'Y': return b == 'Y';
		case 'Z': return b == '5';
		case '1': return b == '1';
		case '2': return b == 'S';
		case '3': return b == 'E';
		case '5': return b == 'Z';
		case '8': return b == '8';
		default: return false;
	}
}

void proc(string & word, bool & pal, bool & mir) {
	for (int i = 0, j = word.length() - 1; i <= j; i++, j--) {
		if (word[i] != word[j]) pal = false;
		if (!reverse(word[i], word[j])) mir = false;
	}
}

int main() {
	string word;
	while (cin >> word) {
		bool pal = true, mir = true;
		proc(word, pal, mir);
		cout << word << " -- ";
		if(pal && mir) cout << "is a mirrored palindrome.";
		else if(mir) cout << "is a mirrored string.";
		else if(pal) cout << "is a regular palindrome.";
		else cout << "is not a palindrome.";
		cout << endl << endl;
	}
	return 0;
}