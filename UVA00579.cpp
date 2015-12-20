#include <cstdio>
#include <cmath>
using namespace std;

double proc(double d){
	d = fabs(d);
	if(d > 180) return 360-d;
	return d;
}

int main() {
	double h, min;
	double angle;
	scanf("%lf:%lf", &h, &min);
	while (h != 0 || min != 0) {
		printf("%.3f\n", proc((((h*60+min)/720)-(min/60))*360));
		scanf("%lf:%lf", &h, &min);
	}
	return 0;
}