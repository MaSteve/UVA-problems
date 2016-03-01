// las12uvas contest PROBLEM F 2015
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> // max...
#include <utility> // pair
#include <complex>
#include <climits> // int, ll...
#include <limits> // double...
#include <cmath> // abs, atan...
#include <cstring> // memset
#include <string>
#include <functional> // greater, less...
#include <bitset>
#include <cctype>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, string> iis;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {
    vector<iis> vec;
	vector<string> v1, v2;
    int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		vec.clear();
		v1.clear();
		v2.clear();
		for(int j = 0; j < 10; j++){
			string name;
			int at, df;
			cin >> name >> at >> df;
			at = -at;
			vec.push_back(iis(ii(at, df), name));
		}
		printf("Case %d:\n", i + 1);
		sort(vec.begin(), vec.end());
		for (int j = 0; j < 5; j++) {
			v1.push_back(vec[j].second);
		}
		for (int j = 0; j < 5; j++) {
			v2.push_back(vec[j+5].second);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int j = 0;
		cout << "(" << v1[j];
		j++;
		for (; j < 5; j++) {
			cout << ", " << v1[j];
		}
		j = 0;
		cout << ")\n(" << v2[j];
		j++;
		for (; j < 5; j++) {
			cout << ", " << v2[j];
		}
		cout<< ")" << endl;
	}
    return 0;
}