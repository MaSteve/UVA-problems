#include <iostream>
using namespace std;

int main() {
    int catalan[11];
    catalan[0] = 1;
    for (int i = 1; i < 11; i++)
        catalan[i] = (catalan[i-1]*2*i*(2*i - 1))/((i+1)*i);
    int n;
    bool first = false;
    while (cin >> n) {
        if (first) printf("\n");
        else first = true;
        printf("%d\n", catalan[n]);
    }
    return 0;
}
