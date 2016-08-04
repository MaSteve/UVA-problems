#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		string a, b;
		cin >> a >> b;
		bool carry = false, zeros = true;
		int i = 0;
		for (; i < a.length() && i < b.length(); i++) {
			int val = a[i] + b[i] - '0' - '0';
			if (carry) val++;
			if (!(zeros && val%10 == 0)) {
				zeros = false;
				printf("%c", val%10 + '0');
			}
			carry = val >= 10;
		}
		for (; i < a.length(); i++) {
			int val = a[i] - '0';
			if (carry) val++;
			if (!(zeros && val%10 == 0)) {
				zeros = false;
				printf("%c", val%10 + '0');
			}
			carry = val >= 10;
		}
		for (; i < b.length(); i++) {
			int val = b[i] - '0';
			if (carry) val++;
			if (!(zeros && val%10 == 0)) {
				zeros = false;
				printf("%c", val%10 + '0');
			}
			carry = val >= 10;
		}
		if (carry) printf("1");
		printf("\n");
	}
	return 0;
}