#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> exchanges;
    int n;
    while (cin >> n && n != 0) {
        exchanges.clear();
        for (int i = 0; i < n; i++) {
            int origin, target;
            cin >> origin >> target;
            exchanges[origin]++;
            exchanges[target]--;
        }
        bool ok = true;
        for (auto it = exchanges.begin(); it != exchanges.end() && ok; ++it) {
            ok = ok && (it->second == 0);
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
}
