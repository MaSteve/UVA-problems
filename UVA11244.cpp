#include <iostream>
#include <string>

using namespace std;

char grid[102][102];

int limx, limy;
int area(int x, int y){
	if(x<0 || x>=limx || y<0 || y>=limy || grid[x][y] != '*') return 0;
	else{
		grid[x][y]='.';
		return 1 + area(x+1, y) + area(x-1, y) + area(x, y+1) + area(x, y-1) + area(x+1, y+1) + area(x-1, y-1) + area(x-1, y+1) + area(x+1, y-1);
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> limy >> limx;
	while(limx != 0 || limy != 0){
		for(int y = 0; y < limy; y++){
			for(int x = 0; x < limx; x++){
				cin >> grid[x][y];
			}
		}
		int count = 0;
		for(int y = 0; y < limy; y++){
			for(int x = 0; x < limx; x++){
				if(area(x, y)==1) count++;
			}
		}
		cout<<count<<endl;
		cin >> limy >> limx;
	}
	return 0;
}