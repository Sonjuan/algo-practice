#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int v, e;
vector<int> link(10005, -1);
tuple<int, int, int> edge[100005];

int find(int x) {
    if(link[x] < 0) return x;
    return link[x] = find(link[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(link[u] == link[v]) link[u]--;
    if(link[u] < link[v]) link[v] = u;
    else    link[u] = v;
    return 1;
}

int main(void) {
    //Kruskal Algorithm
    cin >> v >> e;
    for(int i = 0; i < e; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = {w, a, b};
    }
    std::sort(edge, edge+e);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; ++i) {
        int a, b, w;
        tie(w, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += w;
        cnt++;
        if(cnt == v-1) break;
    }

    cout << ans;

    return 0;
}