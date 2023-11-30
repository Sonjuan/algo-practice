#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

#define X first
#define Y second
typedef long long ll;

int N, M;
int cnt;

vector<int> p(1005, -1);
pair<int,int> loc[1005];
vector<tuple<ll,int,int>> e;

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int a, int b) {
    a = find(a); b = find(b);
    if(a==b) return 0;
    if(p[a] == p[b])p[a]--;
    if(p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return 1;
}

int main(void) {
    cin >> N >> M;
    
    for(int i = 1; i <= N; ++i) {
        int x,y;
        cin >> x >> y;
        loc[i] = {x,y};
    }

    for(int i = 0; i < M; ++i) {
        int u,v;
        cin >> u >> v;
        if(merge(u,v)) {
            cnt++;
        }
    }

    ll len;
    for(int i = 1; i <= N; ++i) {
        for(int j = i+1; j <= N; ++j) {
            int dx = (loc[i].X - loc[j].X);
            int dy = (loc[i].Y - loc[j].Y);
            len = (ll)dx *dx + (ll)dy *dy;
            e.push_back({len, i, j});
        }
    }

    sort(e.begin(), e.end());

    double ans = 0;
    for(auto cur : e) {
        auto [len,u,v] = cur;
        if(!merge(u,v)) continue;
        ans += sqrt(len);
        cnt++;
        if(cnt == N-1) break;
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}