#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
const int INF = 1e9+10;

int N;
int M;

int st;
int en;

vector<int> dist(1005, INF);
vector<int> pre(1005, 0);
vector<pair<int,int>> adj[1005];

int main(void) {
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> st >> en;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[st] = 0;
    pq.push({dist[st], st});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(dist[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]) {
            if(dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }
    cout << dist[en] << endl;
    vector<int> route;
    while(pre[en]) {
        route.push_back(en);
        en = pre[en];
    }
    route.push_back(st);
    cout << route.size() << endl;
    for(int i = route.size()-1; i >= 0; --i) {
        cout << route[i] << " ";
    }

    return 0;
}