#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N;
int M;

vector<tuple<int,int,int>> edge;
vector<int> link(100005, -1);

int find(int x) {
    if(link[x] < 0) return x;
    return link[x] = find(link[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(link[u] == link[v]) link[u] -= 1;
    if(link[u] < link[v]) link[v] = u;
    else link[u] = v;
    return 1;
}

int main(void) {
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edge.push_back({w, a, b});
    }
    
    sort(edge.begin(), edge.end());
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < edge.size(); ++i) {
        auto [w, a, b] = edge[i];
        if(cnt == N-2) break;
        if(!is_diff_group(a, b))  continue;
        cnt++;
        ans += w;
    }

    cout << ans;

    return 0;
}