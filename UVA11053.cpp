#include <cstdio>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<unsigned long, int> soldiers;

int main() {
	int N;
	scanf("%d", &N);
	while (N != 0){
		int a, b;
		scanf("%d %d", &a, &b);
		soldiers.clear();
		int i = 0;
		unsigned long next = 0;
		while (true) {
			if (soldiers.count(next)) break;
			else soldiers.insert(pair<int, int>(next, i));
			i++;
			next = (((a*next)%N)*next + b) % N;
		}
		printf("%d\n", N - (i-soldiers[next]));
		scanf("%d", &N);
	}
	return 0;
}