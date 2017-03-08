#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int LSOne(int n) {
    return n & (-n);
}

void ft_create(vi &ft, int n) {
    ft.assign(n + 1, 0);
}

int ft_rsq(const vi &ft, int b) {
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}

int ft_rsq(const vi &ft, int a, int b) {
    return ft_rsq(ft, b) - (a == 1 ? 0 : ft_rsq(ft, a - 1));
}

void ft_adjust(vi &ft, int k, int v) {
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
}

int binsearch(const vi &ft, int a, int b, int val) {
    if (a == b) return ft_rsq(ft, a + 1) == val? a: -1;
    else if (a > b) return -1;
    int mid = (a+b)/2;
    int ret = ft_rsq(ft, mid + 1);
    if (ret == val) {
        int v = binsearch(ft, a, mid - 1, val);
        if (v == -1) return mid;
        return v;
    }
    else if (ret > val) {
        return binsearch(ft, a, mid - 1, val);
    }
    else return binsearch(ft, mid + 1, b, val);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> K;
        vi ft;
        ft_create(ft, K);
        for (int i = 1; i < K; i++) ft_adjust(ft, i+1, 1);
        bool first = false;
        for (int i = 0; i < K; i++) {
            int val;
            cin >> val;
            int p = binsearch(ft, 0, K - 1, val);
            if (first) printf(" ");
            else first = true;
            printf("%d", p+1);
            ft_adjust(ft, p+1, -1);
        }
        printf("\n");
    }
    return 0;
}
