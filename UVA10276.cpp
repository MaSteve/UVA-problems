#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T, N;
    int pegs[50];
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) pegs[i] = 0;
        bool ok = true;
        int i = 1;
        for (; ok; i++) {
            ok = false;
            for (int j = 0; j < N && !ok; j++) {
                int sq = sqrt(pegs[j] + i);
                if (pegs[j] == 0 || sq*sq == pegs[j] + i)
                    pegs[j] = i, ok = true;
            }
        }
        i -= 2;
        printf("%d\n", i);
    }
    return 0;
}
