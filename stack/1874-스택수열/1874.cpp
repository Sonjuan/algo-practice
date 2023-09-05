#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    int cnt = 1;
    string ans = "";
    stack<int> st;

    while(N--) {
        int t;
        cin >> t;
        while(cnt <= t) {
            st.push(cnt);
            cnt++;
            ans += "+";
        }
        if(st.top() != t) {
            cout << "No";
            return 0;
        }
        st.pop();
        ans += "-";
    }


    cout << ans;

    return 0;
}