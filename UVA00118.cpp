#include <cstdio>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int x, y; //Current position;
	char dir;
	int dircode; // N 0 E 1 S 2 W 3
	bool grid[52][52];
	int maxx, maxy; //Included
	scanf("%d %d\n", &maxx, &maxy);
	for (int i = 0; i <= maxx; i++) 
		for (int j = 0; j <= maxy; j++)
			grid[i][j] = false;
	while (scanf("%d %d %c\n", &x, &y, &dir) != EOF) {
		dircode = dir == 'N'? 0: dir == 'E'? 1: dir == 'S'? 2: 3;
		char str[102];
		bool lost = false;
		scanf("%s", str);
		int i = 0;
		while (true) {
			if (str[i] == 'R') dircode = (dircode+1)%4;
			else if (str[i] == 'L') dircode = (dircode+4-1)%4;
			else if (str[i] == 'F'){
				if (!(x == maxx && dircode == 1) && !(y == maxy && dircode == 0) && !(x == 0 && dircode == 3) && !(y == 0 && dircode == 2)) {
					switch(dircode){
						case 0: y+=1; break;
						case 1: x+=1; break;
						case 2: y-=1; break;
						case 3: x-=1; break;
					}
				}
				else if (!grid[x][y]) {
					lost = true;
					grid[x][y] = true;
				}
			}
			else break;
			if (lost) break;
			i++;
		}
		printf("%d %d %c", x, y, (dircode == 0? 'N': dircode == 1? 'E': dircode == 2? 'S': 'W'));
		if (lost) printf(" LOST");
		printf("\n");
	}
	return 0;
}