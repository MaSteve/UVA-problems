#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

int flood[110][110];
int N, M;

void proc(int i, int j, int & val) {
    if (i >= 0 && j >= 0 && i < N && j < M && flood[i][j] == -1) {
        flood[i][j] = -2;
        val++;
        proc(i-1, j-1, val);
        proc(i, j-1, val);
        proc(i+1, j-1, val);
        proc(i-1, j, val);
        proc(i+1, j, val);
        proc(i-1, j+1, val);
        proc(i, j+1, val);
        proc(i+1, j+1, val);
    }
}

void proc2(int i, int j, int val) {
    if (i >= 0 && j >= 0 && i < N && j < M && flood[i][j] == -2) {
        flood[i][j] = val;
        proc2(i-1, j-1, val);
        proc2(i, j-1, val);
        proc2(i+1, j-1, val);
        proc2(i-1, j, val);
        proc2(i+1, j, val);
        proc2(i-1, j+1, val);
        proc2(i, j+1, val);
        proc2(i+1, j+1, val);
    }
}

int main() {
    int T;
    cin >> T;
    string line;
    getline(cin, line);
    while (T--) {
        getline(cin, line);
        N = M = 0;
        do {
            getline(cin, line);
            M = line.length();
            for (int i = 0; i < M; i++) {
                if (line[i] == 'L') flood[N][i] = 0;
                else flood[N][i] = -1;
            }
            N++;
        } while(cin.peek() == 'L' || cin.peek() == 'W');
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int val = 0;
                proc(i, j, val);
                proc2(i, j, val);
            }
        }
        do {
            getline(cin, line);
            stringstream ss(line);
            int x, y;
            ss >> x >> y;
            printf("%d\n", flood[x-1][y-1]);
        } while(isdigit(cin.peek()));
        if (T) printf("\n");
    }
    return 0;
}
