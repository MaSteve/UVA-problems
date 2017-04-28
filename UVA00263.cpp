#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    unordered_set <int> s;
    int N;
    int v[11];
    while (cin >> N && N) {
        printf("Original number was %d\n", N);
        s.clear();
        int n1, n2, c = 0;
        do {
            c++;
            s.insert(N);
            n1 = 0, n2 = 0;
            int i = 0;
            while (N) {
                v[i] = N % 10;
                N /= 10;
                i++;
            }
            sort(v, v + i);
            for (int j = 0; j < i; j++) {
                n1 *= 10, n2 *= 10;
                n1 += v[j], n2 += v[i - j -1];
            }
            printf("%d - %d = %d\n", n2, n1, n2 - n1);
            N = n2 - n1;
        } while (!s.count(N));
        printf("Chain length %d\n\n", c);
    }
    return 0;
}
