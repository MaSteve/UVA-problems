#include <iostream>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++){
		int cont1 = 0, cont2 = 0, cont3 = 0;
		bool M = false, E = false, fail = false;
		string s;
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '?') {
				if(E) cont3++;
				else if (M) cont2++;
				else cont1++;
			}
			else if(s[i] == 'M') {
				if(M || E) {
					fail = true;
					break;
				}
				M = true;
			}
			else if(s[i] == 'E') {
				if(E) {
					fail = true;
					break;
				}
				E = true;
			}
			else {
				fail = true;
				break;
			}
		}
		if(cont3 == 0 || cont2 == 0 || cont1 == 0 || cont3 != cont1 + cont2) fail = true;
		if (fail) {
			cout << "no-";
		}
		cout << "theorem" << endl;
	}
	return 0;
}