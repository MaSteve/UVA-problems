#include <iostream>
using namespace std;

int main() {
    int t;
    int mask[32];
    cin >> t;
    while (t--) {
        long long n, auxi;
        cin >> n;
        auxi = n;
        for (int i = 0; i < 32; i++) mask[i] = 0;
        for (int i = 0; i < 32; i++) {
            long long bit = auxi & 1;
            int val = auxi & 31;
            mask[val]++;
            auxi >>= 1;
            auxi += bit << 31;
        }
        bool ok = true;
        for (int i = 0; i < 32 && ok; i++) {
            ok = (mask[i] > 0);
        }
        if (ok) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
