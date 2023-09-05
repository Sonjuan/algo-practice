#include <iostream> 
#include <stack>
#include <string>

using namespace std;

int N;
stack<int> st;

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        string op;
        cin >> op;

        int num;
        if(op == "push") {
            cin >> num;
            st.push(num);
        }

        if(op == "pop") {
            if(st.empty()) cout << "-1" << endl;
            else {
                cout << st.top() << endl;
                st.pop();
            }
        }

        if(op == "size") cout << st.size() << endl;
        
        if(op == "empty") {
            if(st.empty()) cout << "1" << endl;
            else cout << "0" << endl;
        }
        
        if(op == "top") {
            if(st.empty()) cout << "-1" << endl;
            else cout << st.top() << endl;
        }
    }

    return 0;
}