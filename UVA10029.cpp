#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;

string dic[25010];
int dp[25010];
int N = 0;

int proc(int i) {
    if (dp[i] == 0) {
        dp[i] = 1;
        for (int j = 0; j < AdjList[i].size(); j++) {
            dp[i] = max(dp[i], 1 + proc(AdjList[i][j]));
        }
    }
    return dp[i];
}

int main() {
    while (cin >> dic[N]) N++;
    AdjList.assign(N, vi());
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (dic[i].length() == dic[j].length()) {
                int diff = 0;
                for (int k = 0; k < dic[j].length() && diff < 2; k++) {
                    if (dic[i][k] != dic[j][k]) diff++;
                }
                if (diff < 2) AdjList[i].push_back(j);
            }
            else if (dic[i].length() == dic[j].length() + 1) {
                int diff = 0;
                for (int k = 0; k < dic[j].length() && diff < 2; k++) {
                    if (dic[i][k + diff] != dic[j][k]) diff++, k--;
                }
                if (diff < 2) AdjList[i].push_back(j);
            }
            else if (dic[i].length() + 1 == dic[j].length()) {
                int diff = 0;
                for (int k = 0; k < dic[i].length() && diff < 2; k++) {
                    if (dic[i][k] != dic[j][k + diff]) diff++, k--;
                }
                if (diff < 2) AdjList[i].push_back(j);
            }
        }
    }
    int M = 0;
    for (int i = 0; i < N; i++) {
        M = max(M, proc(i));
    }
    printf("%d\n", M);
    return 0;
}
