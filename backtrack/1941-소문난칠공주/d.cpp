#include <bits/stdc++.h>
using namespace std;

int isused[6];
vector<int> t(6, 0);
int ans;

void backtrack(int start, int depth, int left) {
    if(left == 0) {
        for(auto i : t) {
            cout << i;
        }
        cout << endl;
        ans++;
        return;
    }
    if(depth == 6) return;

    t[start] = depth;
    backtrack(start+1, depth+1, left-1);
    backtrack(start, depth+1, left);
}

int main(void) {
    backtrack(0,0, 4);
    cout << ans;
    return 0;
}