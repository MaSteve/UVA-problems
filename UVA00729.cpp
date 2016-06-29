#include <iostream>
using namespace std;

void func(int pos, int bits, int N, int H, string & s) {
    if (pos == N) cout << s << endl;
    else {
        if (N - pos > H - bits) s[pos] = '0', func(pos+1, bits, N, H, s);
        if (H > bits) s[pos] = '1', func(pos+1, bits+1, N, H, s);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, H;
        cin >> N >> H;
        string s = string(N, ' ');
        func(0, 0, N, H, s);
        if (T) printf("\n");
    }
    return 0;
}
