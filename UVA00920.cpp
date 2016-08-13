#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

typedef pair<float, float> ff;

int main() {
    priority_queue<ff> pq;
    int C;
    cin >> C;
    while (C--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            ff p;
            cin >> p.first >> p.second;
            pq.push(p);
        }
        float dist = 0, maxi = 0;
        ff last = pq.top();
        pq.pop();
        while (!pq.empty()) {
            if (pq.top().second > maxi) {
                float h = pq.top().second - maxi, H = pq.top().second - last.second, D = last.first - pq.top().first, d;
                d = (D*h)/H;
                dist += sqrt((h*h) + (d*d));
                maxi = pq.top().second;
            }
            last = pq.top();
            pq.pop();
        }
        printf("%.2f\n", dist);
    }
    return 0;
}
