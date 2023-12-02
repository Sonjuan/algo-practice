#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<int> p(100005, -1);
vector<pair<int,int>> xcord;
vector<pair<int,int>> ycord;
vector<pair<int,int>> zcord;
vector<tuple<int,int,int>> e;

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v) {
    u = find(u); v = find(v);
    if(u==v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        xcord.push_back({x,i});
        ycord.push_back({y,i});
        zcord.push_back({z,i});
    }

    sort(xcord.begin(),xcord.end());
    sort(ycord.begin(),ycord.end());
    sort(zcord.begin(),zcord.end());

    for(int i = 1; i < N; ++i) {
        e.push_back({abs(xcord[i-1].first - xcord[i].first), xcord[i-1].second, xcord[i].second});
        e.push_back({abs(ycord[i-1].first - ycord[i].first), ycord[i-1].second, ycord[i].second});
        e.push_back({abs(zcord[i-1].first - zcord[i].first), zcord[i-1].second, zcord[i].second});
    }

    sort(e.begin(), e.end());

    int cnt = 0;
    int ans = 0;

    for(int i = 0; i < e.size(); ++i) {
        auto [w,u,v] = e[i];
        if(!merge(u,v))continue;
        ans += w;
        cnt++;
        if(cnt == N -1) break;
    }
    cout << ans;
    return 0;
}

// 정점의 좌표만 주어진 뒤 간선만 만들때 N^2 보다 낮게 만들 수 있을까?
