#include <iostream>
using namespace std;

int main() {
	int N;
	while (cin >> N && N != -1) {
		unsigned int m = 0, f = 1;
		for (int i = 0; i < N; i++) {
			unsigned int aux = f;
			f += m + 1;
			m = aux;
		}
		printf("%u %u\n", m, f);
	}
	return 0;
}