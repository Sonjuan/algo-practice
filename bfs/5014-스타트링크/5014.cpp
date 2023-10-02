#include <iostream>
#include <queue>

using namespace std;

int F;
int S;
int G;
int U;
int D;

int graph[1000002];

int main(void) {
    cin >> F >> S >> G >> U >> D;
    if(S == G) {
        cout << 0 << endl;
        return 0;
    }
    fill(graph, graph+1000002, -1);
    queue<int> q;
    q.push(S);
    graph[S] = 0;
    while(!q.empty()) {
        int cur = q.front();q.pop();
        int nextU = cur + U;
        int nextD = cur - D;

        if(nextU == G || nextD == G) {
            cout << graph[cur] + 1;
            return 0;
        }
        if(nextU <= F && graph[nextU] == -1) {
            q.push(nextU);
            graph[nextU] = graph[cur] + 1;
        }
        if(nextD >= 1 && graph[nextD] == -1) {
            q.push(nextD);
            graph[nextD] = graph[cur] + 1;
        }
    }

    cout << "use the stairs" << endl;

    return 0;
}

// Think about the bugs If we init graph by 0 instead of -1 