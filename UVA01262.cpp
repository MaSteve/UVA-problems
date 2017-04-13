#include <iostream>
using namespace std;

char grid1[6][5], grid2[6][5];
int mask[5][30], counter[5], val[5];

int main() {
    int T, K;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 30; j++)
                mask[i][j] = 0;
            counter[i] = 0;
        }
        cin >> K;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> grid1[i][j];
                mask[j][grid1[i][j] - 'A'] = 1;
            }
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> grid2[i][j];
                if (mask[j][grid2[i][j] - 'A'] == 1) mask[j][grid2[i][j] - 'A'] = 2, counter[j]++;
            }
        }
        int mult = 1;
        for (int i = 0; i < 5; i++) mult *= counter[i];
        if (K > mult) printf("NO\n");
        else {
            int acum = 0;
            for (int i = 0; i < 5; i++) {
                mult /= counter[i];
                int auxi = acum;
                for (int j = 0; j < counter[i]; j++) {
                    auxi += mult;
                    if (auxi >= K) {
                        acum = auxi - mult;
                        auxi = 0;
                        for (int k = 0; k < 30; k++) {
                            if (mask[i][k] == 2) {
                                if (auxi == j) {
                                    val[i] = k;
                                    break;
                                }
                                auxi++;
                            }
                        }
                        break;
                    }
                }
            }
            for (int i = 0; i < 5; i++) printf("%c", val[i] + 'A');
            printf("\n");
        }
    }
    return 0;
}
