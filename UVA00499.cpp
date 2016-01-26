#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string line;
	int countU[30], countL[30];
	while (getline(cin, line)) {
		int max = 0;
		for (int i = 0; i < 30 ; i++) countL[i] = countU[i] = 0;
		for (int i = 0; i < line.length(); i++) {
			if(isupper(line[i])) if(++countU[line[i]-'A'] > max) max = countU[line[i]-'A'];
			if(islower(line[i])) if(++countL[line[i]-'a'] > max) max = countL[line[i]-'a'];
		}
		for (int i = 0; i < 30; i++) if(countU[i] == max) printf("%c", i + 'A');
		for (int i = 0; i < 30; i++) if(countL[i] == max) printf("%c", i + 'a');
		printf(" %d\n", max);
	}
	return 0;
}