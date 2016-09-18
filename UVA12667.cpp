#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    int n, t, m;
    cin >> n >> t >> m;
    vector<ii> lb;
    for (int i = 0; i < n; i++) lb.push_back(ii(-1, -1));
    vector<vi> sub;
    for (int i = 0; i < n; i++) sub.push_back(vi(t, 0));
    for (int i = 0; i < m; i++) {
        int time, id;
        char p;
        string ver;
        cin >> time >> id >> p >> ver;
        if (ver == "Yes") {
            if (sub[p-'A'][id-1] == 0) {
                sub[p-'A'][id-1] = 1;
                lb[p-'A'].first = id;
                lb[p-'A'].second = time;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%c ", i+'A');
        if (lb[i].first == -1) printf("- -\n");
        else {
            printf("%d %d\n", lb[i].second, lb[i].first);
        }
    }
    return 0;
}
