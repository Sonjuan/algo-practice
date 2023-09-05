#include <iostream>
#include <stack>
using namespace std;

int K;
int input;
stack<int> st;

int main(void) {
    cin >> K;
    for(int i = 0; i < K; ++i) {
        cin >> input;
        if(input == 0) st.pop();
        else           st.push(input);
    }

    long long ans = 0;
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    cout << ans;
    return 0;
}