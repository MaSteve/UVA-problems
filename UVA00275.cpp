#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        int c = 1;
        unordered_map<int, int> mv;
        printf(".");
        while (!(n == 0 || mv.count(n))) {
            if (c%50 == 0) printf("\n");
            mv[n] = c;
            c++;
            n *= 10;
            printf("%d", n/m);
            n %= m;
        }
        printf("\n");
        if (n == 0) printf("This expansion terminates.\n\n");
        else printf("The last %d digits repeat forever.\n\n", c - mv[n]);
    }
    return 0;
}
