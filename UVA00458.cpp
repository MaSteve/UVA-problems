#include <cstdio>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	char c;
	while(scanf("%c", &c) != EOF){
		if(c != '\n') c = char(c-7);
		printf("%c", c);
	}
	return 0;
}