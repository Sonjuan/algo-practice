#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
const int INF = 0x3f3f3f3f;
int N;
int M;
int X;
int graph[1005][1005];

int main(void) {
    cin >> N >> M >> X;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            graph[i][j] = INF;
        }
    }
    
    for(int i = 1; i <=N; ++i) {
        graph[i][i] = 0;
    }

    for(int i = 0; i < M; ++i) {
        int u,v,w;
        cin >>u>>v>>w;
        graph[u][v] = w;
    }

    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <=N; ++j) {
                graph[i][j] = min(graph[i][j] , graph[i][k]+graph[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        ans = max(ans, graph[i][X] + graph[X][i]);
    }
    cout << ans;

    return 0;
}