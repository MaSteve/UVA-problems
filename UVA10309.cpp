#include <iostream>
#include <climits>
using namespace std;

bool grid[10][10];
bool mask[10][10];

void press(int i, int j) {
    mask[i][j] = !mask[i][j];
    grid[i][j] = !grid[i][j];
    if (i > 0) grid[i-1][j] = !grid[i-1][j];
    if (i < 9) grid[i+1][j] = !grid[i+1][j];
    if (j > 0) grid[i][j-1] = !grid[i][j-1];
    if (j < 9) grid[i][j+1] = !grid[i][j+1];
}

void undo() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (mask[i][j]) press(i, j);
}

int proc2() {
    int count = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i-1][j]) press(i, j), count++;
        }
    }
    for (int i = 0; i < 10; i++) if (grid[9][i]) return 100000000;
    return count;
}

int proc() {
    int min = INT_MAX, count;
    for (int i = 0; i < 1024; i++) {
        count = 0;
        for (int j = 0; j < 10; j++) {
            if ((i >> j) % 2) press(0, j), count++;
        }
        int val = proc2() + count;
        if (val < min) min = val;
        undo();
    }
    return min;
}

int main() {
    string title;
    while (getline(cin, title) && title != "end") {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++) {
                char c;
                cin >> c;
                grid[i][j] = (c == 'O');
                mask[i][j] = false;
            }
        printf("%s %d\n", title.c_str(), proc());
        getline(cin, title);
    }
    return 0;
}
