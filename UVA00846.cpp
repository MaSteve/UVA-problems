#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n1, n2;
        cin >> n1 >> n2;
        n2 -= n1;
        if (n2 == 0) {
            printf("0\n");
            continue;
        }
        n2--;
        n1 = ((-1 + floor(sqrt(1+4*n2)))/2) + 1;
        int auxi = n1*(n1-1);
        if (n2-auxi < n1) printf("%d\n", n1*2 - 1);
        else printf("%d\n", n1*2);
    }
    return 0;
}
