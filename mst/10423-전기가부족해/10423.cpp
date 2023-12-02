#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M, K;
vector<int> p(1005,-1);
vector<tuple<int,int,int>> e;
int ans;

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool merge(int u, int v) {
  u = find(u), v = find(v);
  if(u == v) return 0;
  if(p[u] == p[v]) p[u]--;
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}


int main(void) {
    cin >> N >> M >> K;

    int cnt = 0;
    for(int i = 0; i < K; ++i) {
        int s;
        cin >> s; 
        merge(0,s);
        cnt++;
    }
    
    for(int i = 0; i < M; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        e.push_back({w,u,v});
    }

    sort(e.begin(), e.end());

    for(int i = 0; i < e.size(); ++i) {
        auto [w,u,v] = e[i];
        if(!merge(u,v)) continue;
        ans += w;
        cnt++;
        if(cnt == N) break;
    }

    cout << ans;

    return 0;
}

// 간선을 정렬하고 기존의 u - v 가 연결되었나? 에서 
// source - v 가 연결되었나? 로 변환해서 풀어본다.