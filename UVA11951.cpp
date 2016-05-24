#include <cstdio>
using namespace std;

int main() {
    long long grid[100][100], K;
    int N, M, cases;
    scanf("%d", &cases);
    for (int c = 1; c <= cases; c++) {
        scanf("%d %d %lld", &N, &M, &K);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%lld", &grid[i][j]);
                grid[i][j] += i-1 >= 0? grid[i-1][j]: 0;
                grid[i][j] += j-1 >= 0? grid[i][j-1]: 0;
                grid[i][j] -= i-1 >= 0 && j-1 >= 0? grid[i-1][j-1]: 0;
            }
        }
        long long area = 0, cost = 0;
        for (int i0 = 0; i0 < N; i0++) {
            for (int i1 = i0; i1 < N; i1++) {
                for (int j0 = 0; j0 < M; j0++) {
                    for (int j1 = j0; j1 < M; j1++) {
                        long long p = grid[i1][j1];
                        if (i0 > 0) p -= grid[i0-1][j1];
                        if (j0 > 0) p -= grid[i1][j0-1];
                        if (i0 > 0 && j0 > 0) p += grid[i0-1][j0-1];
                        long long a = (i1-i0+1)*(j1-j0+1);
                        if ((a > area && p <= K) || (a == area && p < cost)) area = a, cost = p;
                    }
                }
            }
        }
        printf("Case #%d: %lld %lld\n", c, area, cost);
    }
    return 0;
}
