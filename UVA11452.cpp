#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string line;
	cin >> N;
	getline(cin, line);
	while (N--) {
		getline(cin, line);
		int pos = 0, comp1 = 0, comp2 = 0, i = 1;
		bool found = false;
		while (!found) {
			for (; i < line.length() && !found; i++) {
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
		}
		for (int i = 0; i < 8; i++) cout << line[comp1 + (i%(line.length() - comp1))];
		cout << "..." << endl;
	}
	return 0;
}