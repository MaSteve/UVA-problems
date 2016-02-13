#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	int freqa[30], freqb[30];
	while (getline(cin, a) && getline(cin, b)) {
		for (int i = 0; i < 30; i++) freqa[i] = freqb[i] = 0;
		for (int i = 0; i < a.length(); i++) freqa[a[i]-'a']++;
		for (int i = 0; i < b.length(); i++) freqb[b[i]-'a']++;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < min(freqa[i], freqb[i]); j++) cout << (char) (i+'a');
		}
		cout << endl;
	}
	return 0;
}