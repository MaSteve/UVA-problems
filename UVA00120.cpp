#include <iostream>
using namespace std;

int main() {
	int pancakes[30];
	while (cin >> pancakes[0]) {
		int size = 1;
		while (cin.peek() != '\n') {
			cin >> pancakes[size];
			size++;
		}
		bool first = false;
		for (int k = 0; k < size; k++) {
			if (!first) first = true;
			else cout << " ";
			cout << pancakes[k];
		} cout << endl;
		for (int i = size - 1; i >= 0; i--) {
			int max = pancakes[i], index = i;
			for (int j = 0; j < i; j++) {
				if (pancakes[j] > max) max = pancakes[j], index = j;
			}
			if (index != i) {
				if (index != 0) cout << size - index << " ";
				cout << size - i << " ";
				int p1 = 0, p2 = index;
				while (p1 < p2) {
					int aux = pancakes[p1];
					pancakes[p1] = pancakes[p2];
					pancakes[p2] = aux;
					p1++, p2--;
				}
				p1 = 0, p2 = i;
				while (p1 < p2) {
					int aux = pancakes[p1];
					pancakes[p1] = pancakes[p2];
					pancakes[p2] = aux;
					p1++, p2--;
				}
			}
		}
		cout << 0 << endl;
	}
	return 0;
}