#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int L, W, H;
        cin >> L >> W >> H;
        printf("Case %d: ", i);
        if (L <= 20 && W <= 20 && H <= 20) printf("good\n");
        else printf("bad\n");
    }
    return 0;
}
