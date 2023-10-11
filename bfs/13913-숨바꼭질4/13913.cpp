#include <iostream>
#include <queue>
using namespace std;

int N;
int K;
int graph[100002];
int path[100002];

void print_path(int p) {
    if(path[p] != -1) print_path(path[p]);
    cout << p << " ";
}

int main(void) {
    cin >> N >> K;
    fill(graph, graph+100002, -1);
    fill(path, path+100002, -1);

    queue<int> q;
    q.push(N);
    graph[N] = 0;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        if(cur*2 <= 100000 && graph[cur*2] == -1) {
            q.push(cur*2);
            graph[cur*2] = graph[cur] + 1;
            path[cur*2] = cur;
        }
        if(cur-1 >= 0 && graph[cur-1] == -1) {
            q.push(cur-1);
            graph[cur-1] = graph[cur] + 1;
            path[cur-1] = cur;

        }
        if(cur+1 <= 100000 && graph[cur+1] == -1) {
            q.push(cur+1);
            graph[cur+1] = graph[cur] +1;
            path[cur+1] = cur;
        }
    }

    cout << graph[K] << endl;    
    print_path(K);

    return 0;
}