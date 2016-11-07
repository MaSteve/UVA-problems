#include <iostream>
#include <stack>
using namespace std;

int main() {
    int books[500], N;
    cin >> N;
    while (N--) {
        int m, k;
        cin >> m >> k;
        long long end = 0, ini = 0;
        for (int i = 0; i < m; i++) {
            cin >> books[i];
            end += books[i];
            if (books[i] > ini) ini = books[i];
        }
        while (ini < end) {
            long long mid = (ini+end)/2;
            long long acum = 0, count = 1;
            for (int i = 0; i < m; i++) {
                acum += books[i];
                if (acum > mid) count++, acum = books[i];
            }
            if (count == k) end = mid;
            else if (count > k) ini = mid + 1;
            else end = mid - 1;
        }
        stack<int> s;
        long long acum = 0, scr = 1;
        for (int i = m-1; i >= 0; i--) {
            if (acum + books[i] > ini || scr + i < k) acum = 0, s.push(-1), scr++;
            acum += books[i]; s.push(books[i]);
        }
        bool first = false;
        while (!s.empty()) {
            if (first) printf(" ");
            else first = true;
            if (s.top() == -1) printf("/");
            else printf("%d", s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}
