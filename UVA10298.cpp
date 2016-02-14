#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	while (getline(cin, line) && line != ".") {
		int pos = 0, comp1 = 0, comp2 = 0, i = 1, n = 1;
		bool found = false;
		while (!found) {
			for (; i < line.length() && !found; i++) {
				if (line.length() % i != 0) continue;
				else n = line.length() / i;
				comp2 = i;
				for (; i < line.length() && line[i] == line[comp1]; i++, comp1++) {
					if (comp1 == comp2 - 1) {
						found = true;
						break;
					}
				}
				if (!found) i = comp2;
				comp1 = 0;
			}
			for (; i < line.length() && line[i] == line[comp1]; i++, comp1++);
			if (i != line.length()) found = false, comp1 = 0, i = comp2 + 1;
			else break;
		}
		if (!found) cout << 1 << endl;
		else cout << n << endl;
	}
	return 0;
}