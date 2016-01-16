#include <cstdio>
using namespace std;

bool grid[101][101];

int main(){
	int cases = 1;
	int x, y;
	bool first = true;
	while (scanf("%d %d", &x, &y) && !(x == 0 && y == 0)) {
		if (!first) printf("\n");
		else first = false;
		char c;
		scanf("%c", &c);
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++)	{
				scanf("%c", &c);
				if (c == '*') grid[i][j] = true;
				else grid[i][j] = false;
			}
			scanf("%c", &c);
		}
		printf("Field #%d:\n", cases++);
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++)	{
				if (grid[i][j]) printf("*");
				else  {
					int cont = 0;
					for (int l = -1; l <= 1; l++) {
						for (int m = -1; m <= 1; m++){
							if ((l+i<x && l+i>=0 && m+j<y && m+j>=0) && grid[l+i][m+j]) cont++;
						}
					}
					printf("%d", cont);
				}
			}
			printf("\n");
		}
	}
	return 0;
}