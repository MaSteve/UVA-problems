#include <cstdio>
using namespace std;

long long dateToInt (long long m, long long d, long long y){
	return
		1461*(y+4800+(m-14)/12)/4+367*(m -2-(m-14)/12*12)/12-
		3*((y+4900+(m-14)/12)/100)/4+d-32075;
}

void intToDate (long jd, long long &m, long long &d, long long &y){
	long long x, n, i, j;
	x=jd+68569; n=4*x/146097;x-=(146097*n+3)/4;
	i=(4000*(x+1))/1461001;x-=1461*i/4-31; j=80*x/2447;
	d=x-2447*j/80;x=j/11; m=j+2-12*x;
	y=100*(n-49)+i+x;
}

int main() {
	long long incr, d, m, y;
	while (scanf("%lld %lld %lld %lld", &incr, &d, &m, &y) && !(incr == 0 && d == 0 && m == 0 && y == 0)) {
		long long jd = dateToInt(m, d, y) + incr;
		intToDate(jd, m, d, y);
		printf("%lld %lld %lld\n", d, m, y);
	}
	return 0;
}