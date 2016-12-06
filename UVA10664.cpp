#include <iostream>
#include <sstream>
using namespace std;

int N, sum;
int weights[20];
int DP[201][20];

bool proc(int r, int i) {
    if (i >= N) return (r == sum - r);
    else if (DP[r][i] == -1) {
        DP[r][i] = (proc(r, i+1) || proc(r+weights[i], i+1))? 1: 0;
    }
    return DP[r][i];
}

int main() {
    int T;
    cin >> T;
    string s;
    getline(cin, s);
    while (T--) {
        getline(cin, s);
        istringstream iss(s);
        N = sum = 0;
        int val;
        while (iss >> val) weights[N] = val, N++, sum += val;
            for (int j = 0; j < sum; j++)
                for (int i = 0; i < N; i++)
                    DP[j][i] = -1;
        if (proc(0, 0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
