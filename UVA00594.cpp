#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int aux = 0;
        for (int i = 0; i < 4; i++)
            aux |= ((n>>(8*i))&255) << (8*(3-i));
        printf("%d converts to %d\n", n, aux);
    }
    return 0;
}
