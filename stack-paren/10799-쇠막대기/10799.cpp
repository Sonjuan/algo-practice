#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    string input = "(((()(()()))(())()))(()())";
    stack<int> st;
    int ans = 0;

    for(int i = 0; i < input.size(); ++i) {
        if(input[i] == '(') {
            st.push(i);
        }else if(input[i] == ')') {
            if(i - st.top() == 1) {
                //cutter
                st.pop();
                ans += st.size();
            }else {
                st.pop();
                ans += 1;
            }
        }
    }
    cout << ans;

    return 0;
}