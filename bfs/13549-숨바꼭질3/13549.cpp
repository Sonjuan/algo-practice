#include <iostream>
#include <deque>
using namespace std;

int N;
int K;
int graph[100001];

int main(void) {
    cin >> N >> K;

    deque<pair<int,int>> dq;
    dq.push_back({N, 0});

    fill(graph, graph+100001, -1);
    graph[N] = 0;

    while(!dq.empty()) {
        auto [cur, time] = dq.front(); dq.pop_front();

        if(cur*2 < 100001 && graph[cur*2] == -1) {
            graph[cur*2] = time;
            dq.push_front({cur*2, time});
        }

        if(cur-1 >= 0 && graph[cur-1] == -1) {
            graph[cur-1] = time+1;
            dq.push_back({cur-1, time+1});
        }

        if(cur+1 < 100001 && graph[cur+1] == -1) {
            graph[cur+1] = time+1;
            dq.push_back({cur+1, time+1});
        }       
    }

    cout << graph[K];
    return 0;
}