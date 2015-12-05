#include <iostream>
#include <string>

using namespace std;

char grid[100][100];

int limx, limy;
int inix, iniy;
char water;

int area(int x, int y){
	if(x<0 || x>=limx || y<0 || y>=limy || grid[x][y] != water) return 0;
	else{
		grid[x][y]='q';
		return 1 + area(x+1, y) + area(x-1, y) + area(x, y+1) + area(x, y-1);
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int cases;
	cin >> cases;
	for(int i = 0; i<cases; i++){
		cin >> iniy >> inix;
		string line;
		limx = limy = 0;
		getline(cin, line);
		while(getline(cin, line) && line.size() != 0){
			limx = line.size();
			for(int j = 0; j<limx; j++) grid[j][limy] = line[j];
			limy++;
		}
		water = grid[inix-1][iniy-1];
		cout<<area(inix-1, iniy-1)<<endl;
		if(i<cases-1)cout<<endl;
	}
	return 0;
}