#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    while(n--) {
        int line;
        cin >> line;
        
        vector<int> inputs(line+1, 0);
        for(int i = 1; i <= line; ++i) {
            cin >> inputs[i];
        }
        
        vector<int> vis(line+1, 0);
        queue<int> Q;

        for(int i = 1; i < inputs.size(); ++i) {
            if(vis[i] != 0) continue;
            vis[i] = i;
            int next = inputs[i];

            while(true) {
                if(vis[next] == i) {
                    while(vis[next] != -1) {
                        vis[next] = -1;
                        next = inputs[next];
                    }
                    break;
                }else if(vis[next] == 0) {
                    vis[next] = i;
                    next = inputs[next];
                }else {
                    break;
                }
            }
        }

        int ans = 0;
        for(int i = 1; i < vis.size(); ++i) {
            if(vis[i] != -1) ans++;
        }
        cout << ans << endl;
        inputs.clear();
        vis.clear();
    } 

    return 0;
}