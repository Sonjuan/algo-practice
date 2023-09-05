#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> seq;

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        seq.push_back({start, end});
    }

    sort(seq.begin(), seq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int cnt = 0;
    int time = 0;
    for(int i = 0; i < N; ++i) {
        if(time > seq[i].first) continue;
        cnt++;
        time = seq[i].second;
    }

    cout << cnt;

    return 0;
}