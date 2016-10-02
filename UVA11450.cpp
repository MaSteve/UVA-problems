#include <iostream>
#include <algorithm>
using namespace std;

int garments[20][21];
int costs[20][201];

int main() {
    int N;
    cin >> N;
    while (N--) {
        int M, C;
        cin >> M >> C;
        for (int i = 0; i < C; i++) {
            cin >> garments[i][0];
            for (int j = 1; j <= garments[i][0]; j++) cin >> garments[i][j];
            int * f = &garments[i][1];
            sort(f, f + garments[i][0]);
        }
        int p = -1, j = 1;
        for (int i = 0; i <= M; i++) {
            if (j <= garments[0][0]  && garments[0][j] <= i) p = garments[0][j], j++;
            costs[0][i] = p;
        }
        for (int j = 1; j < C; j++) {
            for (int i = 0; i <= M; i++) {
                int val = -1;
                for (int k = 1; k <= garments[j][0]; k++) {
                    if (i >= garments[j][k]) {
                        if (costs[j-1][i - garments[j][k]] != -1 && costs[j-1][i - garments[j][k]] + garments[j][k] > val) val = costs[j-1][i - garments[j][k]] + garments[j][k];
                    }
                }
                costs[j][i] = val;
            }
        }
        if (costs[C-1][M] == -1) printf("no solution\n");
        else printf("%d\n", costs[C-1][M]);
    }
    return 0;
}
