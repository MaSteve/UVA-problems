#include <cstdio>
using namespace std;

int main() {
	int cases;
	float grades[1001];
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int N;
		scanf("%d", &N);
		float acum = 0; 
		for (int j = 0; j < N; j++) {
			scanf("%f", &grades[j]);
			acum += grades[j];
		}
		acum /= N;
		float cont = 0;
		for (int j = 0; j < N; j++) {
			if (grades[j]>acum) cont++;
		}
		printf("%.3f%%\n", float((cont*100)/N));
	}
	return 0;
}