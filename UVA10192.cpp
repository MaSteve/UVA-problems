// This file contains practically the same code as UVA10405.cpp
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int cases = 1;
	string s1, s2;
	int grid[102][102];
	for (int i = 0; i < 102; i++) grid[0][i] = grid[i][0] = 0;
	while (getline(cin, s1) && s1 != "#") {
		getline(cin, s2);
		bool lock = false;
		for (int i = 0; i < s1.length(); i++) {
			for (int j = 0; j < s2.length(); j++){
				grid[i+1][j+1] = grid[i+1][j];
				if (s1[i] == s2[j] && !lock) grid[i+1][j+1]++, lock = true;
				if (grid[i][j+1] >= grid[i+1][j+1]) grid[i+1][j+1] = grid[i][j+1], lock = false;
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n", cases, grid[s1.length()][s2.length()]);
		cases++;
	}
	return 0;
}