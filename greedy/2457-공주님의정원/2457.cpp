#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main(void) {
    cin >> N;
    vector<pair<int, int>> s;
    for(int i = 0; i < N; ++i) {
        int bmonth, bday, emonth, eday;
        cin >> bmonth >> bday >> emonth >> eday;
        s.push_back({bmonth*100+bday, emonth*100+eday});
    }
    sort(s.begin(), s.end(), [](const pair<int, int>& a, const pair<int, int>&b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    int ans = 0;
    int start = 301;
    int end = 301;
    // for(auto i : s) {
    //     cout << i.first << " " << i.second << endl;
    // }
    
    // 1. Maximize End in current start time;
    // 2. if Maximized, move start to End;
    // 3. move back to 1.
    for(int i = 0; i < N; ++i) {
        if(s[i].first > start && s[i].second > end) {
            ans++;
            start = end;
        }
        if(s[i].first <= start && s[i].second >= end) {
            end = s[i].second;
            if(end > 1130) {
                ans++;
                break;
            }
        }
    }

    if(end <= 1130) cout << 0;
    else cout << ans;

    return 0;
}

