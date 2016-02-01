#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int grid[1002][1002];
	for (int i = 0; i < 1002; i++) grid[0][i] = grid[i][0] = 0;
	while (getline(cin, s1) && getline(cin, s2)) {
		bool lock = false;
		for (int i = 0; i < s1.length(); i++) {
			for (int j = 0; j < s2.length(); j++){
				grid[i+1][j+1] = grid[i+1][j];
				if (s1[i] == s2[j] && !lock) grid[i+1][j+1]++, lock = true;
				if (grid[i][j+1] >= grid[i+1][j+1]) grid[i+1][j+1] = grid[i][j+1], lock = false;
			}
		}
		cout << grid[s1.length()][s2.length()] << endl;
	}
	return 0;
}