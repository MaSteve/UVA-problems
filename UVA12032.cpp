#include <iostream>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int c = 1; c <= cases; c++) {
        int N, prev = 0, k = 0, max = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int step;
            cin >> step;
            if (step - prev > max) {
                if (step - prev <= k) k++, max = k;
                else k = step - prev, max = k-1;
            } if (step - prev == max) max--;
            prev = step;
        }
        printf("Case %d: %d\n", c, k);
    }
    return 0;
}
