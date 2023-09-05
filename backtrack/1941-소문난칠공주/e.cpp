#include <bits/stdc++.h>
using namespace std;

vector<int> t;
int ans;

void backtrack(int start, int left) {
    if(left == 0) {
        for(auto i : t) {
            cout << i;
        }
        cout << endl;
        ans++;
        return;
    }
    for(int i = start; i <= 6; ++i) {
        t.push_back(i);
        backtrack(i+1, left-1);
        t.pop_back();
    }

}

int main(void) {
    backtrack(1, 4);
    cout << ans;
    return 0;
}