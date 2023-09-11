#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> seq;


int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        seq.push_back({a, 1});
        seq.push_back({b, -1});
    }

    sort(seq.begin(), seq.end());

    int cur = 0;
    int ans = 0;
    
    for(auto i : seq) {
        if(i.second == 1) {
            cur += 1;
            ans = max(ans, cur);
        }else if(i.second == -1) {
            cur -= 1;
        }
    }

    cout << ans;

    return 0;
}