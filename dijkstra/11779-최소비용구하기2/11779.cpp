#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

vector<pair<int, int>> adj[1005];
const int INF = 1e9+10;

int d[1005];
int pre[1005];

int v, e, st, en;

int main(void) {
    cin >> v >> e;
    fill(d, d+v+1, INF);
    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> st >> en;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    d[st] = 0;
    pq.push({d[st], st});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }

    cout << d[en] << endl;
    vector<int> route;
    while(pre[en]) {
        route.push_back(en);
        en = pre[en];
    }
    route.push_back(st);
    cout << route.size() << endl;
    for(int i = route.size()-1; i >= 0; i--) {
        cout << route[i] << " ";
    }

    return 0;
}