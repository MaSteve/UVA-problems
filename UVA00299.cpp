#include <iostream>
using namespace std;

int train[51], L;

int sort() {
    int ret = 0, auxi;
    for (int i = 0; i < L; i++) {
        for (int j = i + 1; j < L; j++) {
            if (train[i] > train[j]) ret++, auxi = train[j], train[j] = train[i], train[i] = auxi;
        }
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        cin >> L;
        for (int i = 0; i < L; i++) cin >> train[i];
        int sol = sort();
        printf("Optimal train swapping takes %d swaps.\n", sol);
    }
    return 0;
}
