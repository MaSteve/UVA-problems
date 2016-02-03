#include <iostream>
#include <string>
using namespace std;

int main() {
	string c;
	getline(cin, c);
	while (getline(cin, c) && c != "___________") {
		int pot = 1, code = 0;
		for (int i = 9; i > 1; i--) {
			if (c[i] == '.') continue;
			code += c[i] == 'o'? pot: 0;
			pot *= 2;
		}
		cout << (char)code;
	}
	return 0;
}