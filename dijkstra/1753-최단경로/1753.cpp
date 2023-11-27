#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int V;
int E;
int Start;
vector<pair<int,int>> graph[20'005];
const int INF = 0x3f3f3f3f;
//https://www.infoarena.ro/12-ponturi-pentru-programatorii-cc
vector<int> d(20005, INF);

int main(void) {
    cin >> V >> E;
    cin >> Start;

    for(int i =0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w,v});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    d[Start] = 0;
    pq.push({d[Start], Start});
    
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : graph[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    for(int i = 1; i <= V; ++i) {
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }

    return 0;
}