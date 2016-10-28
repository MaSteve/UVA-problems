#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    int K;
    cin >> K;
    int grid[52][52];
    unordered_map<int, int> m;
    unordered_set<int> set;
    for (int c = 1; c <= K; c++) {
        m.clear();
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> grid[i][0];
            set.clear();
            for (int j = 1; j <= grid[i][0]; j++) {
                cin >> grid[i][j];
                if (!set.count(grid[i][j])) m[grid[i][j]]++, set.insert(grid[i][j]);
            }
        }
        printf("Case %d:", c);
        int total = 0;
        for (int i = 0; i < N; i++) {
            int acum = 0;
            set.clear();
            for (int j = 1; j <= grid[i][0]; j++)
                if (m[grid[i][j]] == 1 && !set.count(grid[i][j])) acum++, set.insert(grid[i][j]);
            grid[i][0] = acum*100;
            total += acum;
        }
        for (int i = 0; i < N; i++) printf(" %.6f%%", double(grid[i][0])/total);
        printf("\n");
    }
    return 0;
}
