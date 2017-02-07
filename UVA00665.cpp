#include <iostream>
using namespace std;

int main() {
    int w[100];
    bool m[100];
    int r[100];
    int M;
    cin >> M;
    while (M--) {
        int N, K;
        char c;
        cin >> N >> K;
        for (int i = 0; i < N; i++) w[i] = 0, m[i] = false;
        while (K--) {
            int P;
            cin >> P;
            for (int i = 0; i < 2*P; i++) cin >> r[i];
            cin >> c;
            if (c == '=') {
                for (int i = 0; i < 2*P; i++) w[r[i] - 1] = 0, m[r[i] - 1] = true;
            } else {
                bool cond = (c == '<');
                int l1 = cond? P: 2*P, l2 = cond? 2*P: P;
                for (int i = cond? 0: P; i < l1; i++) {
                    if (!m[r[i] - 1]) {
                        w[r[i] - 1]--;
                        if (w[r[i] - 1] >= 0) w[r[i] - 1] = 0, m[r[i] - 1] = true;
                    }
                }
                for (int i = cond? P: 0; i < l2; i++) {
                    if (!m[r[i] - 1]) {
                        w[r[i] - 1]++;
                        if (w[r[i] - 1] <= 0) w[r[i] - 1] = 0, m[r[i] - 1] = true;
                    }
                }
            }
        }
        int count = 0, bad = -1;
        for (int i = 0; i < N; i++) {
            if (!m[i]) count++, bad = i + 1;
        }
        if (count > 1 || bad == -1) printf("0\n");
        else printf("%d\n", bad);
        if (M) printf("\n");
    }
    return 0;
}
