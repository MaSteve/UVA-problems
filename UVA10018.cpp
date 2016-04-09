#include <cstdio>
using namespace std;

bool revadd(unsigned int & n){
	unsigned int inv = 0, aux = n;
	while (aux != 0) {
		inv *= 10;
		inv += (aux%10);
		aux /= 10;
	}
	if (inv == n) return true;
	n += inv; 
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		unsigned int p;
		scanf("%u", &p);
		int cont = 0;
		while (!revadd(p)) cont++;
		if (cont == 0) {
			p *= 2;
			while (!revadd(p)) cont++;
		}
		printf("%d %u\n", cont, p);
	}
	return 0;
}