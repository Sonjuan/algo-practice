#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
int C;
int M;
vector<tuple<int, int, int>> orders;
int truck[2002];

int main(void) {
    cin >> N >> C >> M;
    int st, en, c;
    int ans = 0;

    for(int i = 0; i < M; ++i) {
        cin >> st >> en >> c;
        orders.push_back({en, st, c});
    }
    
    sort(orders.begin(), orders.end());

    for(auto v : orders) {
        tie(en, st, c) = v;
        bool loadable = true;
        for(int i = st; i < en; ++i) {
            c = min(c, C - truck[i]);
            if(!c) {
                loadable = false;
                break;
            }
        }
        if(loadable) {
            ans += c;
            for(int i = st; i < en; ++i) {
                truck[i] += c;
            }
        }
    }
    
    cout << ans;

    return 0;
}