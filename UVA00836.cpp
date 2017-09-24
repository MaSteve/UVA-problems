#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int height[30][30];

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    getline(cin, s);
    while (n--) {
        vector<string> v;
        while (getline(cin, s) && s != "") {
            v.push_back(s);
        }
        for (int i = 1; i <= v.size(); i++) {
            for (int j = 1; j <= v[i - 1].length(); j++) {
                int val = v[i - 1][j - 1] == '1'? 1: 0;
                height[i][j] = val? height[i - 1][j] + val: 0;
            }
        }
        int maxi = 0;
        for (int i = 1; i <= v.size(); i++) {
            for (int j = 1; j <= v[i - 1].length(); j++) {
                int val = v[i - 1][j - 1] == '1'? 1: 0;
                int smaxi = 0, h = 100;
                for (int k = j; k >= 1; k--) {
                    if (height[i][k] == 0) break;
                    h = min(h, height[i][k]);
                    smaxi = max(smaxi, (j - k + 1) * h);
                }
                maxi = max(maxi, smaxi);
            }
        }
        printf("%d\n", maxi);
        if (n) printf("\n");
    }
    return 0;
}
