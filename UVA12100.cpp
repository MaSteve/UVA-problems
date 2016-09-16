#include <iostream>
#include <queue>
using namespace std;

int main() {
    int jobs[9];
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 9; i++) jobs[i] = 0;
        int n, m;
        cin >> n >> m;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            jobs[v-1]++;
            if (i == m) v += 10;
            q.push(v-1);
        }
        int cp = 8, min = 0;
        while (jobs[cp] == 0 && cp >= 0) cp--;
        bool stop = false;
        while (!stop) {
            if (cp > (q.front()%10)) q.push(q.front());
            else {
                min++;
                jobs[cp]--;
                while (jobs[cp] == 0 && cp >= 0) cp--;
                if (q.front() >= 10) stop = true;
            }
            q.pop();
        }
        printf("%d\n", min);
    }
    return 0;
}
