#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> table[52];
vector<int> score(52);
int N;

int bfs(int u) {
    vector<int> dist(N+1, -1);
    queue<int> q;

    q.push(u);
    dist[u] = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int v : table[cur]) {
            if(dist[v] != -1) continue;
            q.push(v);
            dist[v] = dist[cur] + 1;
        }
    }    
    int val = *max_element(dist.begin()+1, dist.begin()+N+1);
    
    return val == 0 ? 999999 : val;
}

int main(void) {
    cin >> N;

    int u = 0, v = 0;
    while(u != -1 && v != -1) {
        cin >> u >> v;
        table[u].push_back(v);
        table[v].push_back(u);
    }

    for(int i = 1; i <= N; ++i) {
        score[i] = bfs(i);
    }

    int MinScore = *min_element(score.begin()+1, score.begin()+N+1);
    vector<int> result;
    for(int i= 1; i <= N; ++i) {
        if(score[i] == MinScore){
            result.push_back(i);
        }
    }

    cout << MinScore << " " << result.size() << endl;
    for(auto i : result) {
        cout << i << " ";
    }

    return 0;
}