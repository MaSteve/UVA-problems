#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> dp[15][15];

void proc(int chocolate, int vanilla) {
    if (dp[chocolate][vanilla].empty()) {
        if (chocolate == 0) dp[chocolate][vanilla].insert(string(vanilla, 'V'));
        else if (vanilla == 0) dp[chocolate][vanilla].insert(string(chocolate, 'C'));
        else  {
            proc(chocolate-1, vanilla); proc(chocolate, vanilla-1);
            for (auto it = dp[chocolate-1][vanilla].begin(); it != dp[chocolate-1][vanilla].end(); ++it) {
                dp[chocolate][vanilla].insert("C"+(*it));
            }
            for (auto it = dp[chocolate][vanilla-1].begin(); it != dp[chocolate][vanilla-1].end(); ++it) {
                dp[chocolate][vanilla].insert("V"+(*it));
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int chocolate, vanilla;
        cin >> chocolate >> vanilla;
        proc(chocolate, vanilla);
        bool first = false;
        for (auto it = dp[chocolate][vanilla].begin(); it != dp[chocolate][vanilla].end(); ++it) {
            if (first) printf(" ");
            else first = true;
            printf("%s", (*it).c_str());
        }
        printf("\n");
    }
    return 0;
}
