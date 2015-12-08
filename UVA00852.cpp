#include <iostream>
using namespace std;

char grid[9][9];
bool proc[9][9];

int area(int x, int y, bool & black, bool & white){
	if(x<0 || x>=9 || y<0 || y>=9) return 0;
	else if (grid[x][y] != '.'){
		if(grid[x][y] == 'X') black = true;
		if(grid[x][y] == 'O') white = true;
		return 0;
	}
	else if(!proc[x][y]){
		proc[x][y]=true;
		return 1 + area(x+1, y, black, white) + area(x-1, y, black, white) + area(x, y+1, black, white) + area(x, y-1, black, white);
	}
	return 0;
}

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++){
    	int white = 0, black = 0;
    	for(int y = 0; y < 9; y++){
    		for (int x = 0; x < 9; x++){
    			cin >> grid[x][y];
    			if(grid[x][y] == 'X') black++;
    			else if (grid[x][y] == 'O') white++;
    			proc[x][y] = false;
    		}
    	}
    	for(int y = 0; y < 9; y++){
    		for (int x = 0; x < 9; x++){
    			bool bblack = false, bwhite = false;
    			int a = area(x, y, bblack, bwhite);
    			if(bblack && !bwhite) black += a;
    			if(!bblack && bwhite) white += a;
    		}
    	}
    	cout << "Black " << black << " White " << white << endl;
    }
    return 0;
}