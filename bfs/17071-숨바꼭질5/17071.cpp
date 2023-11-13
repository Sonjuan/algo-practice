#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N;
int K;
int board[500005];
int vis[2][500005];

int main(void) {
    cin >> N >> K;
    queue<pair<int,int>> q;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 500005; ++j) {
            vis[i][j] = -1;
        }
    }

    vis[0][N] = 0;
    q.push({N, 0});

    while(!q.empty()) {
        auto [cN, cT] = q.front(); q.pop();
        cT += 1;
        for(int nxt : {cN+1, cN-1, cN*2}) {
            if(nxt < 0 || nxt > 500000) continue;
            if(vis[cT%2][nxt] != -1) continue;
            vis[cT%2][nxt] = cT;
            q.push({nxt, cT});
        }
    }

    int ans = 0;
    bool found = false;
    while(K <= 500000) {
        if(vis[ans%2][K] <= ans) {
            found = true;
            break;
        }
        ans += 1;
        K += ans;
    }

    if(found) cout << ans;
    else cout << -1;
    return 0;
}