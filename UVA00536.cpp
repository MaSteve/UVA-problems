#include <iostream>
using namespace std;

struct node {
    node * left = nullptr;
    node * right = nullptr;
    char c;

    void build(string & preord, string & inord, int & idx, int & idy, bool * mask) {
        c = preord[idx];
        mask[c-'A'] = true;
        idx++;
        if (c != inord[idy]) {
            left = new node();
            left->build(preord, inord, idx, idy, mask);
        }
        idy++;
        if (idy >= inord.length() || mask[inord[idy]-'A']) return;
        right = new node();
        right->build(preord, inord, idx, idy, mask);
    }
    void clear() {
        if (left != nullptr) {
            left->clear();
            delete left;
        }
        if (right != nullptr) {
            right->clear();
            delete right;
        }
    }
    void print() {
        if (left != nullptr) {
            left->print();
        }
        if (right != nullptr) {
            right->print();
        }
        printf("%c", c);
    }
};

struct BT {
    bool mask[30];
    node * root = nullptr;

    BT(string & preord, string & inord) {
        for (int i = 0; i < 30; i++) mask[i] = false;
        root = new node();
        int idx = 0, idy = 0;
        root->build(preord, inord, idx, idy, mask);
    }
    ~BT() {
        if (root != nullptr) {
            root->clear();
            delete root;
        }
    }
    void print() {
        if (root != nullptr) {
            root->print();
        }
        printf("\n");
    }
};

int main() {
    string preord, inord;
    while (cin >> preord >> inord) {
        BT bt(preord, inord);
        bt.print();
    }
    return 0;
}
