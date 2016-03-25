#include <iostream>
#include <string>
using namespace std;

int chartomatches(char c, int pos) {
	switch(c) {
		case '9': return pos == 0? 3: pos == 1? 4: pos == 2? 6: 0;
		case '8': return pos == 0? 5: pos == 1? 8: pos == 2? 9: 0;
		case '7': return pos == 0? 4: pos == 1? 6: pos == 2? 7: 0;
		case '6': return pos == 0? 3: pos == 1? 4: pos == 2? 5: 0;
		case '5': return pos == 0? 2: pos == 1? 2: pos == 2? 3: 0;
		case '4': return pos == 0? 3: pos == 1? 4: pos == 2? 5: 0;
		case '3': return pos == 0? 3: pos == 1? 6: pos == 2? 6: 12;
		case '2': return pos == 0? 2: pos == 1? 4: pos == 2? 4: 8;
		case '1': return pos == 0? 1: pos == 1? 2: pos == 2? 2: 4;
	}
	return 0;
}

int matches(string number) {
	int n = 0;
	for (int i = 0; i < number.length(); i++) {
		n += chartomatches(number[i], number.length()-i-1);
	}
	return n;
}

int main() {
	string number;
	while (cin >> number) {
		cout << matches(number) << endl;
	}
	return 0;
}