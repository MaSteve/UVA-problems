#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int N, M;
vector<vi> AdjList;
vi * awake, * auxi;

int main() {
    awake = new vi();
    auxi = new vi();
    while (cin >> N >> M) {
        AdjList.assign(30, vi());
        awake->assign(30, 0);
        auxi->assign(30, 0);
        string s;
        getline(cin, s);
        getline(cin, s);
        (*awake)[s[0] - 'A'] = 1;
        (*awake)[s[1] - 'A'] = 1;
        (*awake)[s[2] - 'A'] = 1;
        for (int i = 0; i < M; i++) {
            getline(cin, s);
            AdjList[s[0] - 'A'].push_back(s[1] - 'A');
            AdjList[s[1] - 'A'].push_back(s[0] - 'A');
        }
        if (N <= 3) printf("WAKE UP IN, 0, YEARS\n");
        else {
            bool stop = false;
            int t = 0;
            while (!stop) {
                bool change = false;
                for (int i = 0; i < 30; i++) {
                    (*auxi)[i] = (*awake)[i];
                    if (!(*awake)[i]) {
                        int act = 0;
                        for (int j = 0; j < AdjList[i].size(); j++) {
                            int v = AdjList[i][j];
                            if ((*awake)[v]) act++;
                        }
                        if (act >= 3) {
                            (*auxi)[i] = 1;
                            change = true;
                        }
                    }
                }
                stop = !change;
                vi * sw = awake;
                awake = auxi;
                auxi = sw;
                t++;
            }
            int count = 0;
            for (int i = 0; i < 30; i++) {
                count += (*awake)[i];
            }
            if (count >= N && t > 1) printf("WAKE UP IN, %d, YEARS\n", t - 1);
            else printf("THIS BRAIN NEVER WAKES UP\n");
        }
    }
    delete awake;
    delete auxi;
    return 0;
}
