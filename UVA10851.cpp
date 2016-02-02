#include <iostream>
#include <string>
using namespace std;

int main() {
	string matrix[10];
	int N;
	cin >> N;
	while (N--) {
		for (int i = 0; i < 10; i++) cin >> matrix[i];
		for (int j = 1; j < matrix[0].length()-1; j++) {
			int pot = 1, c = 0;
			for (int i = 1; i < 9; i++) {
				c += matrix[i][j] == '/'? 0: pot;
				pot *= 2;
			}
			cout << (char)c;
		}
		cout << endl;
	}
	return 0;
}