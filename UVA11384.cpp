#include <iostream>
using namespace std;

int proc(int N) {
    if (N == 1) return 1;
    return 1 + proc(N/2);
}

int main() {
    int N;
    while (cin >> N) {
        printf("%d\n", proc(N));
    }
    return 0;
}
