#include <cstdio>
#include <unordered_map>
#include <utility>
using namespace std;

int grid[100][100], ind;
unordered_map<int, int> m;

void reset(int i) {
    for (int j = 0; j <= i; j++) {
        grid[i][j] = grid[j][i] = 1000000;
    }
}

void floyd() {
    for (int k = 0; k < ind; k++)
        for (int i = 0; i < ind; i++)
            for (int j = 0; j < ind; j++)
                if (grid[i][k] + grid[k][j] < grid[i][j]) {
                    grid[i][j] = grid[i][k] + grid[k][j];
                }
}

int main() {
    int i, j, cases = 1;
    while (scanf("%d %d", &i, &j) && !(i == 0 && j == 0)) {
        m.clear();
        ind = 0;
        do {
            if (!m.count(i)) m[i] = ind, reset(ind), ind++;
            if (!m.count(j)) m[j] = ind, reset(ind), ind++;
            grid[m[i]][m[j]] = 1;
        } while (scanf("%d %d", &i, &j) && !(i == 0 && j == 0));
        floyd();
        double sum = 0;
        for (int i = 0; i < ind; i++) {
            for (int j = 0; j < ind; j++) {
                if (i != j) sum += grid[i][j];
            }
        }
        sum /= (ind - 1)*ind;
        printf("Case %d: average length between pages = %.3lf clicks\n", cases++, sum);
    }
    return 0;
}
