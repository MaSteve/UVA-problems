#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int value(char c) {
	switch(c) {
		case 'M': return 1000;
		case 'D': return 500;
		case 'C': return 100;
		case 'L': return 50;
		case 'X': return 10;
		case 'V': return 5;
		case 'I': return 1;
	}
	return -1;
}

int toArabic(string number) {
	int n = 0;
	int level = 2000;
	for (int i = 0; i < number.length(); i++) {
		if (value(number[i]) > level) {
			int val = value(number[i]) - 2*level;
			level = value(number[i]);
			n += val;
		}
		else {
			level = value(number[i]);
			n += value(number[i]);
		}
	}
	return n;
}

string value(char c, int pos) {
	switch(c) {
		case '9': return pos == 0? "IX": pos == 1? "XC": pos == 2? "CM": "";
		case '8': return pos == 0? "VIII": pos == 1? "LXXX": pos == 2? "DCCC": "";
		case '7': return pos == 0? "VII": pos == 1? "LXX": pos == 2? "DCC": "";
		case '6': return pos == 0? "VI": pos == 1? "LX": pos == 2? "DC": "";
		case '5': return pos == 0? "V": pos == 1? "L": pos == 2? "D": "";
		case '4': return pos == 0? "IV": pos == 1? "XL": pos == 2? "CD": "";
		case '3': return pos == 0? "III": pos == 1? "XXX": pos == 2? "CCC": "MMM";
		case '2': return pos == 0? "II": pos == 1? "XX": pos == 2? "CC": "MM";
		case '1': return pos == 0? "I": pos == 1? "X": pos == 2? "C": "M";
	}
	return "";
}

string toRoman(string number) {
	string n = "";
	for (int i = 0; i < number.length(); i++) {
		n += value(number[i], number.length()-i-1);
	}
	return n;
}

int main() {
	string number;
	while (cin >> number) {
		if (isdigit(number[0])) cout << toRoman(number) << endl;
		else cout << toArabic(number) << endl;
	}
	return 0;
}