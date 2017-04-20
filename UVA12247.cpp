#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, X, Y;
    bool deck[53];
    for (int i = 0; i < 53; i++) deck[i] = false;
    while (cin >> A >> B >> C >> X >> Y && !(A == 0 && B == 0 && C == 0 && X == 0 && Y == 0)) {
        int P1[3], P2[3];
        P1[0] = A; P1[1] = B; P1[2] = C;
        sort(P1, P1 + 3);
        deck[A] = deck[B] = deck[C] = deck[X] = deck[Y] = true;
        int sol = -1;
        int match[3];
        for (int i = 1; i <= 52 && sol == -1; i++) {
            if (deck[i]) continue;
            match[0] = match[1] = match[2] = false;
            P2[0] = X; P2[1] = Y; P2[2] = i;
            sort(P2, P2 + 3);
            int count = 0;
            for (int k = 0; k <= 2; k++) {
                int auxi = -1;
                for (int j = 2; j >= 0; j--) {
                    if (!match[j]) {
                        if (auxi == -1) auxi = j;
                        if (P2[j] < P1[k]) {
                            auxi = j, count++;
                            break;
                        }
                    }
                }
                match[auxi] = true;
            }
            if (count < 2) sol = i;
        }
        printf("%d\n", sol);
        deck[A] = deck[B] = deck[C] = deck[X] = deck[Y] = false;
    }
    return 0;
}
