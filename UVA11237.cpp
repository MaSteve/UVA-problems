#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int c, n;
    int sweets[100002];
    int pos[100002];
    while (cin >> c >> n && !(c == 0 && n == 0)) {
        memset(pos, 0, c*4);
        bool first = false;
        bool stop = false;
        for (int i = 0; i < n; i++) {
            int auxi;
            cin >> auxi;
            if (stop) continue;
            sweets[i] = auxi;
            sweets[i] += i > 0? sweets[i-1]: 0;
            sweets[i] %= c;
            if (pos[sweets[i]] != 0 || sweets[i] == 0) {
                for (int j = pos[sweets[i]]+1; j <= i+1; j++) {
                    if (first) printf(" ");
                    else first = true;
                    printf("%d", j);
                }
                stop = true;
                continue;
            }
            pos[sweets[i]] = i+1;
        }
        printf("\n");
    }
    return 0;
}
