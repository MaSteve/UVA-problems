#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

map<long, int> c;

int collatz(long n){
    if(c.count(n) == 0){
        if(n%2==0){
            c[n] = collatz(n/2)+1;
        } else{
            c[n] = collatz((3*n)+1)+1;
        }
    }
    return c[n];
}

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	c[0]=0; c[1]=1;
	for(long i = 2; i<= 1000000; i++) collatz(i);
	int i, j, ia, ja;
	while(scanf("%d %d",&i, &j)!=EOF){
		int max = 0;
		if(j<i){
			ja = i; ia = j;
		} else {
			ja = j; ia = i;
		}
		for(int m = ia; m<=ja; m++)
			if(c[m]>max) max = c[m];
		printf("%d %d %d\n",i,j,max);
	}
	return 0;
}