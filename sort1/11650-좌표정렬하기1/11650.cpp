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
        if(a.first == b.first) {
            return a.second < b.second;
        }else {
            return a.first < b.first;
        }
    });

    for(int i = 0; i < n; ++i) {
        cout << p[i].first << p[i].second << endl;
    }

    return 0;
}