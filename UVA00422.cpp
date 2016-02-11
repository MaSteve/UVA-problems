#include <iostream>
#include <string>
#include <utility>
using namespace std;

string grid[101];

bool inside(int x, int y, int m, int n) {
	return x < m && x >= 0 && y < n && y >= 0;
}

bool search(const string & word, int x, int y, int pos, const int & incrx, const int & incry, const int & m, const int & n, pair<int, int> & last) {
	if(word[pos] == grid[x][y]) {
		if (pos < word.length()-1) {
			int found = false;
			if (inside(x+incrx, y+incry, m, n)) found = search(word, x+incrx, y+incry, pos+1, incrx, incry, m, n, last);
			return found;
		} else {
			last.first = x;
			last.second = y;
			return true;
		}
	} else return false;
}

int main() {
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) cin >> grid[i];
	string word;
	pair<int, int> last;
	while (cin >> word && word != "0") {
		bool found = false;
		for (int x = 0; x < m && !found; x++) {
			for (int y = 0; y < m && !found; y++) {
				for (int incrx = -1; incrx <= 1 && !found; incrx++) {
					for (int incry = -1; incry <= 1 && !found; incry++) {
						if (incrx == 0 && incry == 0) continue;
						found = search(word, x, y, 0, incrx, incry, m, m, last);
						if (found) printf("%d,%d %d,%d\n", x+1, y+1, last.first+1, last.second+1);
					}
				}
			}
		}
		if (!found) printf("Not found\n");
	}
	return 0;
}