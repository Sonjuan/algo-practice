#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main(void) {
    pair<int, int> p[10002];
    cin >> n;

    for(int i =0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p+n, [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }else {
            return a.second < b.second;
        }
    });

    for(int i = 0; i < n; ++i) {
        cout << p[i].first << p[i].second << endl;
    }

    return 0;
}
