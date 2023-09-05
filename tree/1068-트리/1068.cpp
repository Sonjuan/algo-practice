#include <iostream>
#include <vector>

using namespace std;

int N;
int ROOT;
int DEL;
vector<int> tree[52];

int tree_search(int cur) {
    int cnt = 0;
    int flag = 0;
    for(int nxt : tree[cur]) {
        if(nxt == DEL) continue;
        flag = 1;
        cnt += tree_search(nxt);
    }

    if(!flag) cnt += 1;
    return cnt;
}

int main(void) {
    cin >> N;
    for(int cur = 0; cur < N; ++cur) {
        int parent;
        cin >> parent;

        if(parent == -1) {
            ROOT = cur;
            continue;
        }
        tree[parent].push_back(cur);
    }
    cin >> DEL;

    if(DEL == ROOT) cout << "0";
    else            cout << tree_search(ROOT);
    
    return 0;
}