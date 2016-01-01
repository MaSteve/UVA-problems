#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	int n = 1;
	while (getline(cin, word) && word != "#") {
		cout << "Case " << n++ << ": ";
		if (word == "HELLO") cout << "ENGLISH";
		else if (word == "HOLA") cout << "SPANISH";
		else if (word == "HALLO") cout << "GERMAN";
		else if (word == "BONJOUR") cout << "FRENCH";
		else if (word == "CIAO") cout << "ITALIAN";
		else if (word == "ZDRAVSTVUJTE") cout << "RUSSIAN";
		else cout << "UNKNOWN";
		cout << endl;
	}
	return 0;
}