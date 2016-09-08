#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, B;
        cin >> N >> B;
        int extras = 0;
        for (int i = 0; i < B; i++) {
            int K, c, choco = 1;
            cin >> K;
            for (int j = 0; j < K; j++) {
                int a;
                cin >> a;
                choco *= a;
                choco %= N;
            }
            extras += choco;
            extras %= N;
        }
        printf("%d\n", extras);
    }
    return 0;
}
