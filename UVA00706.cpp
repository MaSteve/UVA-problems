#include <iostream>
#include <string>
using namespace std;

int main() {
	int s;
	string n;
	while (cin >> s >> n && !(s == 0 && n == "0")) {
		for (int i = 0; i < n.length(); i++) {
			char c = n[i] != '1' && n[i] != '4'? '-': ' ';
			cout << ' ';
			for (int j = 0; j < s; j++) {
				cout << c;
			}
			cout << ' ';
			if (i != n.length() - 1) cout << ' ';
		} cout << endl;
		for (int j = 0; j < s; j++) {
			for (int i = 0; i < n.length(); i++) {
				cout << (n[i] != '1' && n[i] != '2' && n[i] != '3' && n[i] != '7'? '|': ' ');
				for (int j = 0; j < s; j++) {
					cout << ' ';
				}
				cout << (n[i] != '5' && n[i] != '6'? '|': ' ');
				if (i != n.length() - 1) cout << ' ';
			} cout << endl;
		}
		for (int i = 0; i < n.length(); i++) {
			char c = n[i] != '1' && n[i] != '7' && n[i] != '0'? '-': ' ';
			cout << ' ';
			for (int j = 0; j < s; j++) {
				cout << c;
			}
			cout << ' ';
			if (i != n.length() - 1) cout << ' ';
		} cout << endl;
		for (int j = 0; j < s; j++) {
			for (int i = 0; i < n.length(); i++) {
				cout << (n[i] != '1' && n[i] != '3' && n[i] != '4' && n[i] != '5' && n[i] != '7' && n[i] != '9'? '|': ' ');
				for (int j = 0; j < s; j++) {
					cout << ' ';
				}
				cout << (n[i] != '2'? '|': ' ');
				if (i != n.length() - 1) cout << ' ';
			} cout << endl;
		}
		for (int i = 0; i < n.length(); i++) {
			char c = n[i] != '1' && n[i] != '7' && n[i] != '4'? '-': ' ';
			cout << ' ';
			for (int j = 0; j < s; j++) {
				cout << c;
			}
			cout << ' ';
			if (i != n.length() - 1) cout << ' ';
		} cout << endl << endl;
	}
	return 0;
}