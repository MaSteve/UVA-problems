#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string grid[51];

bool inside(int x, int y, int m, int n) {
	return x < m && x >= 0 && y < n && y >= 0;
}

bool search(const string & word, int x, int y, int pos, const int & incrx, const int & incry, const int & m, const int & n) {
	if(tolower(word[pos]) == tolower(grid[x][y])) {
		if (pos < word.length()-1) {
			int found = false;
			if (inside(x+incrx, y+incry, m, n)) found = search(word, x+incrx, y+incry, pos+1, incrx, incry, m, n);
			return found;
		} else {
			return true;
		}
	} else return false;
}

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int m, n, k;
		cin >> m >> n;
		for (int i = 0; i < m; i++) cin >> grid[i];
		cin >> k;
		string word;
		for (int i = 0; i < k; i++) {
			cin >> word;
			bool found = false;
			for (int x = 0; x < m && !found; x++) {
				for (int y = 0; y < n && !found; y++) {
					for (int incrx = -1; incrx <= 1 && !found; incrx++) {
						for (int incry = -1; incry <= 1 && !found; incry++) {
							if (incrx == 0 && incry == 0) continue;
							found = search(word, x, y, 0, incrx, incry, m, n);
							if (found) printf("%d %d\n", x+1, y+1);
						}
					}
				}
			}
		}
		if (cases) printf("\n");
	}
	return 0;
}