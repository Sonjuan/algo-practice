#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int N, M, en;
const int INF = 0x3f3f3f3f;
vector<pair<int,int>> graph[1005];
vector<int> xt(1005, INF);
vector<int> dt(1005, INF);

int main(void) {
    cin >> N >> M >> en;
    for(int i = 0; i < M; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({w,v});
    }

    xt[en] = 0;
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > tpq;
    tpq.push({xt[en], en});
    while(!tpq.empty()) {
        auto cur = tpq.top(); tpq.pop();
        if(xt[cur.Y] != cur.X) continue;
        for(auto nxt : graph[cur.Y]) {
            if(xt[nxt.Y] <= xt[cur.Y] + nxt.X) continue;
            xt[nxt.Y] = xt[cur.Y] + nxt.X;
            tpq.push({xt[nxt.Y], nxt.Y});
        }
    }

    int cand = 0;
    for(int st = 1; st <= N; ++st) {
        dt = vector<int>(1005,INF);
        dt[st] = 0;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({dt[st], st});
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if(dt[cur.Y] != cur.X) continue;
            for(auto nxt : graph[cur.Y]) {
                if(dt[nxt.Y] <= dt[cur.Y] + nxt.X) continue;
                dt[nxt.Y] = dt[cur.Y] + nxt.X;
                pq.push({dt[nxt.Y], nxt.Y});
            }
        }
        cand = max(cand, dt[en] + xt[st]);
    }
    cout << cand;

    return 0;
}