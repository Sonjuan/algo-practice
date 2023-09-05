#include <iostream>
#include <stack>

using namespace std;

int N;
stack<pair<int, int>> st;
int ans[1'000'000];

int main(void) {
    cin >> N;
    int input;
    for(int i = 0; i < N; ++i) {
        cin >> input;
        while(!st.empty() && st.top().first < input) {
            ans[st.top().second] = input;
            st.pop();
        }
        st.push({input, i});
    }

    while(!st.empty()) {
        ans[st.top().second] = -1;
        st.pop();
    }

    for(int i = 0; i < N; ++i)
        cout << ans[i] << " ";

    return 0;
}