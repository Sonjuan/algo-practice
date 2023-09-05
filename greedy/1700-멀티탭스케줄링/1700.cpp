#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int K;
int seq[105];
int hit[105];

int main(void) {
    cin >> N >> K;
    
    for(int i = 1; i <= K; ++i) {
        cin >> seq[i];
    }

    int ans = 0;
    int cnt = 0;
    for(int i = 1; i <= K; ++i) {
        int cur = seq[i];
        if(hit[cur]) continue;
        if(cnt < N) {
            hit[cur] = 1;
            cnt++;
        }else {
            vector<pair<int, int>> search;
            for(int x = 1; x <= K; ++x) {
                if(!hit[x]) continue;
                int vis = 0;
                for(int y = i + 1; y <= K; ++y) {
                    if(seq[y] == x) {
                        search.push_back({y, x});
                        vis = 1;
                        break;
                    }
                }
                if(!vis) search.push_back({K+1, x});
            }   
            sort(search.begin(), search.end(), greater<pair<int, int>>());
            int target = search[0].second;
            hit[target] = 0;
            ans++;
            hit[cur] = 1;
        }
    }

    cout << ans;
    return 0;
}