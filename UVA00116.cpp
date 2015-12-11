#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
int grid[11][101];
ii path[11][101];
int limx, limy;

void proc(){
	for(int i = 0; i < limx; i++){
		path[i][limy-1].first = grid[i][limy-1];
		path[i][limy-1].second = -1;
	}
	for(int j = limy-2; j >= 0; j--){
		for(int i = 0; i < limx; i++){
			int low = min(min((limx+i-1)%limx, (i+1)%limx), i);
			int high = max(max((limx+i-1)%limx, (i+1)%limx), i);
			int middle = (limx+i-1)%limx + (i+1)%limx + i - low - high;
			int cost = min(min(path[low][j+1].first, path[middle][j+1].first),path[high][j+1].first);
			path[i][j].first = cost + grid[i][j];
			path[i][j].second = cost == path[low][j+1].first? low: cost == path[middle][j+1].first? middle: high;
		}
	}
}

int main(){
	while(scanf("%d %d", &limx, &limy) != EOF){
		for(int i = 0; i < limx; i++){
			for(int j = 0; j < limy; j++){
				scanf("%d", &grid[i][j]);
			}
		}
		proc();
		int mincost = path[0][0].first, pos = 0;
		for(int i = 1; i < limx; i++){
			if(mincost > path[i][0].first) {
				mincost = path[i][0].first;
				pos = i;
			}
		}
		for(int j = 0; j < limy; j++){
			printf("%d", pos+1);
			pos = path[pos][j].second;
			if(j < limy -1) printf(" ");
		}
		printf("\n%d\n", mincost);
	}
	return 0;
}
