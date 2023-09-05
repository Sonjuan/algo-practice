#include <bits/stdc++.h>
using namespace std;

// 0, 1 bfs solution
int n, k;
int dist[200002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int MX = 200000;
    fill(dist, dist+MX, -1);
    deque<int> dq;
    dq.push_back(n);
    dist[n]=0;
    while(!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        if( 2*cur < MX && dist[2*cur] == -1) {
            dist[2*cur] = dist[cur];
            dq.push_front(2*cur);
        }
        for(int next : {cur-1, cur+1}) {
            if(next < 0 || next >= MX || dist[next] != -1) continue;
            dist[next] = dist[cur]+1;
            dq.push_back(next);
        }
    }
    cout << dist[k];
    return 0;
}