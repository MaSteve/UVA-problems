#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

/*int N; THAT'S THE WAY YOU SHOULDN'T SOLVE THIS PROBLEM.
int stores[22];
bool visited[22];
int mini;

void proc(int ini, int acum, int last, bool first) {
    if (acum > mini) return;
    int end = true;
    for (int i = 0; i < N; i++) {
        if (first) ini = i, last = stores[i];
        if (!visited[i]) {
            visited[i] = true;
            proc(ini, acum + (int)fabs(stores[i]-last), stores[i], false);
            visited[i] = false;
            end = false;
        }
    }
    if (end) mini = min(acum + (int)fabs(stores[ini]-last), mini);
}*/

int main() {
    int t, N;
    cin >> t;
    while (t--) {
        cin >> N;
        int mini = INT_MAX, maxi = -1, val;
        for (int i = 0; i < N; i++) {
            cin >> val;
            mini = min(mini, val), maxi = max(maxi, val);
        }
        printf("%d\n", 2*(maxi-mini));
    }
    return 0;
}
