#include <cstdio>
#include <stack>
using namespace std;

int main() {
	int n;
	stack<bool> s;
	while (scanf("%d", &n) && n != 0) {
		int bits = 0, aux = n;
		while (aux != 0) {
			bits += aux % 2;
			s.push(aux % 2 != 0);
			aux >>= 1;
		}
		printf("The parity of ");
		while (!s.empty()) printf("%d", s.top()), s.pop();
		printf(" is %d (mod 2).\n", bits);
	}
	return 0;
}