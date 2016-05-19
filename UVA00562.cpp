#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> ii;
typedef unordered_map<int, ii> uiii;
typedef unordered_map<int, uiii> uiv;

int N, total, mini;
int val[101];
uiv reg;

int func(int sum1, int sum2, int p) {
    if (2*sum2 - total >= mini) return mini;
    if (reg[sum1][p].second != 1) {
        if (p < N) reg[sum1][p].first = min(func(min(sum1 + val[p], sum2), max(sum1 + val[p], sum2), p+1), func(sum1, sum2 + val[p], p+1));
        else reg[sum1][p].first = sum2 - sum1;
        reg[sum1][p].second = 1;
    }
    mini = min(reg[sum1][p].first, mini);
    return reg[sum1][p].first;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        reg.clear();
        cin >> N;
        total = 0;
        for (int i = 0; i < N; i++) cin >> val[i], total += val[i];
        mini = total + 1;
        cout << func(0, 0, 0) << endl;
    }
    return 0;
}
