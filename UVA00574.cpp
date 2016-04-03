#include <cstdio>
using namespace std;

int n, t, n2;
int nums[12][2];
int sol[12], once;

void proc(int pos, int sum, int elems) {
	if (sum == t) {
		once = true;
		bool first = false;
		for (int i = 0; i < pos; i++) {
			for (int j = 0; j < sol[i]; j++) {
				if (first) printf("+");
				else first = true;
				printf("%d", nums[i][0]);
			}
		}
		printf("\n");
	}
	if (sum < t && pos < n && sum + (n2-elems)*nums[pos][0] >= t) {
		sol[pos] = nums[pos][1];
		for (int i = 0; sol[pos] >= 0; sol[pos]--, i++) {
			proc(pos+1, sum + (sol[pos]*nums[pos][0]), elems+i);
		}
		sol[pos] = 0;
	}

}

int main() {
	for (int i = 0; i < 12; i++) sol[i] = 0;
	while (scanf("%d %d", &t, &n) && !(t == 0 && n == 0)) {
		n2 = n;
		once = false;
		printf("Sums of %d:\n", t);
		int prev = -1, cont = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i-cont][0]);
			if (nums[i-cont][0] == prev) {
				cont ++;
				nums[i-cont][1]++;
			} else {
				prev = nums[i-cont][0];
				nums[i-cont][1] = 1;
			} 
		}
		n -= cont;
		proc(0, 0, 0);
		if (!once) printf("NONE\n");
	}
	return 0;
}