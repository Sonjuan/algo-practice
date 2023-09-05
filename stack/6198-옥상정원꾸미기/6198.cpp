#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack<int> s;
int n;
ll ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  ll h;
  while (n--) {
    cin >> h;
    while(!s.empty() && s.top() <= h)
      s.pop();
    ans += s.size();
    s.push(h);
  }
  cout << ans;
  return 0;
}

// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;

// int main(void) {
//     int N;
//     cin >> N;

//     vector<int> inputs(N, 0);
//     for(int i = 0; i < N; ++i) {
//         cin >> inputs[i];
//     }

//     int cnt = 0;
//     stack<int> st;
//     for(int i = inputs.size()-1; i >= 0; --i) {
//         while(!st.empty() && st.top() < inputs[i]) {
//             st.pop();
//             cnt++;
//         }
//         st.push(inputs[i]);
//     }

//     return 0;
// }