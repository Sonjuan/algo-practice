#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n, m;

    int x, idx, cur;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        pq.push({x, i});
        tie(cur, idx) = pq.top();
        while(idx < max(0, i - m + 1)) {
            pq.pop();
            tie(cur, idx) = pq.top()
        }
        cout << cur << endl;
    }

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int main(void) {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n, m;
//     deque<pair<int, int>> dq;

//     cin >> n >> m;

//     for(int i = 0; i < n; ++i) {
//         int num;
//         cin >> num;

//         while(!dq.empty() && dq.back().second >= num) {
//             dq.pop_back();
//         }

//         dq.push_back({i, num});

//         if(dq.front().first <= i - m) {
//             dq.pop_front();
//         }
//         cout << dq.front().second << endl;
//     }


//     return 0;
// }