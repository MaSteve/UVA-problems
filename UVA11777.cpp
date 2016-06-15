#include <iostream>
#include <algorithm>
using namespace std;

char grade(int count) {
    if (count >= 90) return 'A';
    if (count >= 80) return 'B';
    if (count >= 70) return 'C';
    if (count >= 60) return 'D';
    return 'F';
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int count = 0, t1, t2, final, a, c1, c2, c3;
        cin >> t1 >> t2 >> final >> a >> c1 >> c2 >> c3;
        count = t1 + t2 + final + a;
        int mini = min(c1, min(c2, c3));
        count += (c1+c2+c3-mini)/2;
        printf("Case %d: %c\n", i, grade(count));
    }
    return 0;
}
