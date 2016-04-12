#include <iostream>
#include <string>
using namespace std;

void proc(string & s, bool & leap, bool & huluculu, bool & bulukulu) {
	bool d3, d4, d5, d11, d100, d400;
	d4 = (10*(s[s.length()-2]-'0') + (s[s.length()-1]-'0')) % 4 == 0;
	d5 = s[s.length()-1] == '0' || s[s.length()-1] == '5';
	d100 = s[s.length()-1] == '0' && s[s.length()-2] == '0';
	d400 = d100 && ((10*(s[s.length()-4]-'0') + (s[s.length()-3]-'0')) % 4 == 0);
	long long sum = 0, altsum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i]-'0';
		if (i%2) altsum -= (s[i]-'0');
		else altsum += (s[i]-'0');
	}
	d3 = sum%3 == 0;
	d11 = altsum%11 == 0;
	leap = d4 && (!d100 || d400);
	huluculu = d3 && d5;
	bulukulu = d5 && d11 && leap;
}

int main() {
	string s;
	bool first = false;
	while (getline(cin, s)) {
		if (first) printf("\n");
		else first = true;
		bool leap, huluculu, bulukulu;
		proc(s, leap, huluculu, bulukulu);
		if (!leap && !huluculu && !bulukulu) printf("This is an ordinary year.\n");
		else {
			if (leap) printf("This is leap year.\n");
			if (huluculu) printf("This is huluculu festival year.\n");
			if (bulukulu) printf("This is bulukulu festival year.\n");
		}
	}
	return 0;
}