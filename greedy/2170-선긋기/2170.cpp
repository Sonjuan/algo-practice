#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> seq;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        seq.push_back({x, y});
    }
    sort(seq.begin(), seq.end());

    long long res = 0;
    int s = seq[0].first;
    int e = seq[0].second;
    res += abs(e - s);

    for(int i = 1; i < seq.size(); ++i) {
        auto [x, y] = seq[i];
        if (x <= e && e < y) {
            res += abs(y - e);
            e = y;
        }else if(x > e) {
            s = x;
            e = y;
            res += abs(y - x);
        }
    }
    cout << res;

    return 0;
}