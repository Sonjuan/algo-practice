#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
int dist[102][102];

const int INF = 0x3f3f3f3f;

int main(void) {
    cin >> N >> M;

    for(int i = 1; i <= N; ++i)
        fill(dist[i], dist[i]+1+N, INF);

    while(M--) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;        
    }

    for(int i = 1; i <= N; ++i) 
        dist[i][i] = 0;

    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int MIN = 0x3f3f3f3f;
    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        int sum = 0;
        
        for(int j = 1; j <= N; ++j)
            sum += dist[i][j];
        
        if(MIN > sum) {
            MIN = sum;
            ans = i;
        }
    }

    cout << ans;

    return 0;
}
// for(int i = 1; i <= N; ++i) {
//     for(int j = 1; j <= N; ++j) {
//         if(dist[i][j] == INF) cout << "0 ";
//         else cout << dist[i][j] << " "; 
//     }
//     cout << endl;
// }
