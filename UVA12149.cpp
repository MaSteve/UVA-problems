#include <cstdio>
using namespace std;

int main() {
    int squares[101];
    squares[0] = 0;
    for (int i = 1; i < 101; i++) squares[i] = i*i + squares[i-1];
    int N;
    while (scanf("%d", &N) && N != 0) printf("%d\n", squares[N]);
    return 0;
}
