#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int ROOT;
int maxBL = 0;
int maxB = 0;
int cnt = 1;

vector<int> lchild(10002);
vector<int> rchild(10002);
vector<int> seq(10002);
vector<int> parent(10002);

void get_rank(int u) {
    if(lchild[u] != -1) get_rank(lchild[u]);
    seq[u] = cnt++;
    if(rchild[u] != -1) get_rank(rchild[u]);
}

void levelOrder(int root) {
    int levelCnt = 0;
    queue<int> q;
    q.push(root);

    while(!q.empty()) {
        vector<int> level;
        int s = q.size();
        levelCnt++;

        for(int i = 0; i < s; ++i) {
            int u = q.front(); q.pop();
            level.push_back(seq[u]);
            if(lchild[u] != -1) q.push(lchild[u]);
            if(rchild[u] != -1) q.push(rchild[u]);
        }

        int temp = *max_element(level.begin(), level.end()) - *min_element(level.begin(), level.end()) + 1;
        if(temp > maxB) {
            maxB = temp;
            maxBL = levelCnt;
        }        
    }
}

int main(void) {
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        int node, left, right;
        cin >> node >> left >> right;
        if(left != -1)  parent[left] = node;
        if(right != -1) parent[right] = node;
        lchild[node] = left;
        rchild[node] = right;        
    }
    for(int i = 1; i <= N; ++i) {
        if(!parent[i]) ROOT = i;
    }

    get_rank(ROOT);
    levelOrder(ROOT);

    cout << maxBL << " " << maxB;

    return 0;
}