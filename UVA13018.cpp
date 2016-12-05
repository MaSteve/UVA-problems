#include <iostream>
using namespace std;

int main() {
    int N, M;
    int counts[41];
    bool first = false;
    while (cin >> N >> M) {
        if (first) printf("\n");
        else first = true;
        int maxi = 0;
        for (int i = 0; i < 41; i++) counts[i] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                counts[i+j]++;
                if (counts[i+j] > maxi) maxi = counts[i+j];
            }
        }
        for (int i = 0; i < 41; i++)
            if (counts[i] == maxi) printf("%d\n", i);
    }
    return 0;
}
