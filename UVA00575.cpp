#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	while (cin >> n && n != "0") {
		int val = 0, pot = 2;
		for (int i = n.size()-1; i>=0; i--, pot = pot<<1) {
			val += (n[i]-'0')*(pot-1);
		}
		cout << val << endl;
	}
}