#include <iostream>
#include <algorithm>
using namespace std;

int fib[200];

void fix(int i) {
    while (fib[i] > 1) {
        fib[i] -= 2;
        if (i == 0) {
            fib[1] += 1;
            if (fib[1] > 1) fix(1);
        } else if (i == 1) {
            fib[2] += 1;
            fib[0] += 1;
            if (fib[2] > 1) fix(2);
            if (fib[0] > 1) fix(0);
        } else {
            fib[i+1] += 1;
            fib[i-2] += 1;
            if (fib[i+1] > 1) fix(i+1);
            if (fib[i-2] > 1) fix(i-2);
        }
    }
}

int main() {
    string n1, n2;
    bool bln = false;
    while (cin >> n1 >> n2) {
        if (bln) printf("\n");
        else bln = true;
        int l = max(n1.length(), n2.length()) + 40;
        for (int i = l; i >= 0; i--) {
            fib[i] = 0;
            if (i < n1.length()) fib[i] += n1[n1.length() - 1 - i] - '0';
            else fib[i] += 0;
            if (i < n2.length()) fib[i] += n2[n2.length() - 1 - i] - '0';
            else fib[i] += 0;
        }
        for (int i = l; i >= 0; i--) {
            if (fib[i] > 1) fix(i);
        }
        bool stop = false;
        while (!stop) {
            stop = true;
            if (fib[0] > 1) stop = false, fix(0);
            for (int i = 1; i <= l; i++) {
                if (fib[i] > 1) {
                    stop = false;
                    fix(i);
                }
                if (fib[i] == 1 && fib[i-1] == 1) {
                    stop = false;
                    fib[i] = fib[i-1] = 0;
                    fib[i+1]++;
                }
            }
        }
        bool first = false;
        for (int i = l; i >= 0; i--) {
            if (first || fib[i] != 0) {
                first = true;
                printf("%d", fib[i]);
            }
        }
        if (!first) printf("0");
        printf("\n");
    }
    return 0;
}
