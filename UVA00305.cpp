#include <iostream>
using namespace std;

int main() {
    /*for (int k = 1; k < 14; k++) {
        bool sol = false;
        int m = k;
        for (; !sol; m++) {
            int deaths = 0, next = 0;
            while (!sol) {
                next = (2*k - deaths + next + m - 1) % (2*k - deaths);
                deaths++;
                if (next < k) break;
                if (deaths == k) sol = true;
            }
        }
        printf("%d %d\n", k, m-1);
    }*/
    int k;
    int sol[14] = { 0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
    while (cin >> k && k != 0) printf("%d\n", sol[k]);
    return 0;
}
