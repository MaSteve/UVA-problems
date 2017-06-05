#include <iostream>
using namespace std;

int h, k;
int sol[10], curr[10];
int MAX;

bool check(int i, int l, int L, int H) {
    if (i < 0) return false;
    if (i == 0) return true;
    if (H < h) {
        bool ret = check(i - curr[l], l, L, H + 1);
        for (int d = l + 1; d <= L && !ret; d++)
            ret = ret || check(i - curr[d], d, L, H + 1);
        return ret;
    }
    return false;
}

void proc(int maxi, int l) {
    if (l == k) {
        if (maxi > MAX) {
            MAX = maxi;
            for (int i = 0; i < k; i++) {
                sol[i] = curr[i];
            }
        }
    } else {
        for (int i = curr[l-1] + 1; i < maxi + 2; i++) {
            curr[l] = i;
            int j = maxi + 1;
            for (; check(j, 0, l, 0); j++);
            proc(j - 1, l + 1);
        }
    }
}

int main() {
    while (cin >> h >> k && !(h == 0 && k == 0)) {
        curr[0] = 1;
        MAX = 0;
        proc(h, 1);
        for (int i = 0; i < k; i++) {
            printf("%3d", sol[i]);
        }
        printf(" ->%3d\n", MAX);
    }
    return 0;
}
