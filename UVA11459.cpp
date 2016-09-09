#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

int main() {
    int cases, a, b, c;
    cin >> cases;
    while (cases--) {
        unordered_map<int, int> pos;
        unordered_map<int, int> ls;
        cin >> a >> b >> c;
        for (int i = 0; i < b; i++) {
            int f, s;
            cin >> f >> s;
            ls[f] = s;
        }
        bool end = false;
        for (int i = 0, player = 0; i < c; i++, player = (player + 1) % a) {
            int dice;
            cin >> dice;
            if (!end) {
                pos[player] = pos[player] + dice;
                if (ls[pos[player] + 1]) pos[player] = ls[pos[player] + 1] - 1;
                if (pos[player] >= 99) {
                    pos[player] = 99; end = true;
                }
            }
        }
        for (int i = 0; i < a; i++) {
            printf("Position of player %d is %d.\n", i+1, pos[i]+1);
        }
    }
    return 0;
}
