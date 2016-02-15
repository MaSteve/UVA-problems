#include <iostream>
#include <iostream>
using namespace std;

string grid[4];
bool mask[4][4];

bool inside(int x, int y) {
	return x < 4 && x >= 0 && y < 4 && y >= 0;
}

bool search(const string & word, int x, int y, int pos) {
	if(word[pos] == grid[x][y] && !mask[x][y]) {
		mask[x][y] = true;
		if (pos < word.length()-1) {
			int found = false;
			for (int i = -1; i <= 1 && !found; i++)
				for (int j = -1; j <= 1 && !found; j++)
					if (inside(x+i, y+j)) found |= search(word, x+i, y+j, pos+1);
			mask[x][y] = false;
			return found;
		} else {
			mask[x][y] = false;
			return true;
		}
	} else return false;
}

int points(const string & word) {
	switch(word.length()) {
		case 7: return 5;
		case 6: return 3;
		case 5: return 2;
		case 4:
		case 3: return 1;
		case 2:
		case 1:
		case 0: return 0;
		default: return 11;
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 4; j++) cin >> grid[j];
		int M;
		cin >> M;
		string word;
		int count = 0;
		for (int j = 0; j < M; j++) {
			cin >> word;
			bool stop = false;
			for (int x = 0; x < 4 && !stop; x++)
				for (int y = 0; y < 4 && !stop; y++)
					if (search(word, x, y, 0)) count += points(word), stop = true;
		}
		printf("Score for Boggle game #%d: %d\n", i, count);
	}
	return 0;
}