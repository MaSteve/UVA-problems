#include <iostream>
using namespace std;

int grid[25][25];
int N, M;

void proc(int i, int j, int & val) {
    if (i < N && j < M && i >= 0 && j >= 0 && grid[i][j]) {
        grid[i][j] = 0;
        val++;
        proc(i+1, j, val);
        proc(i+1, j+1, val);
        proc(i, j+1, val);
        proc(i-1, j+1, val);
        proc(i-1, j, val);
        proc(i-1, j-1, val);
        proc(i, j-1, val);
        proc(i+1, j-1, val);
    }
}

int main() {
    int T;
    cin >> T;
    string line;
    getline(cin, line);
    getline(cin, line);
    while (T--) {
        N = 0, M = 0;
        while (getline(cin, line) && line != "") {
            M = line.size();
            N++;
            for (int i = 0; i < M; i++) {
                grid[N-1][i] = line[i] - '0';
            }
        }
        int maxi = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int val = 0;
                proc(i, j, val);
                if (val > maxi) maxi = val;
            }
        }
        printf("%d\n", maxi);
        if (T) printf("\n");
    }
    return 0;
}
