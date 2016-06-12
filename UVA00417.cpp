#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<string, int> map;
char aux[5];

void proc(int level, char start, int limit) {
    for (int i = start + 1; i <= 'z'; i++) {
        aux[level] = i;
        if (level == limit) map.insert(make_pair(string(aux), map.size()+1));
        else proc(level + 1, i, limit);
    }
}

int main() {
    for (int i = 0; i <= 4; i++) {
        aux[i] = 0;
        proc(0, 'a'-1, i);
    }
    string w;
    while (cin >> w) {
        if (map.count(w)) printf("%d\n", map[w]);
        else printf("0\n");
    }
    return 0;
}
