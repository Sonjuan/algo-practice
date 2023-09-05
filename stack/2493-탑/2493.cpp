#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int N;
stack<pair<int, int>> tower;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    tower.push({100000001, 0});
    for( int i = 1; i <= N; ++i) {
        int height;
        cin >> height;
        while(tower.top().X < height) {
            tower.pop();
        }
        cout << tower.top().Y << " ";
        tower.push({height, i});
    }
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

//     stack<int> st;
//     for(int i = inputs.size()-1; i >= 0; --i) {
//         if(st.empty()) {
//             st.push(i);
//         }else {
//             while(!st.empty() && inputs[st.top()] < inputs[i]) {
//                 inputs[st.top()] = i + 1;
//                 st.pop();
//             }
//             st.push(i);
//         }
//     }

//     while(!st.empty()) {
//         inputs[st.top()] = 0;
//         st.pop();
//     }

//     for(int i = 0; i < inputs.size(); ++i) {
//         if(i == inputs.size()-1) cout << inputs[i];
//         else                     cout << inputs[i] << " ";
//     }

//     return 0;
// }