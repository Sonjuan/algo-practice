#include <iostream>
#include <stack>

using namespace std;

int N;
int seq[500002];
long long ans;

stack<pair<int, int>> st;

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    for(int i = 0; i < N; ++i) {
        int dup = 1;
        while(!st.empty() && st.top().first <= seq[i]) {
            ans += st.top().second;
            if(st.top().first == seq[i]) dup += st.top().second;
            st.pop(); 
        }
        if(!st.empty()) ans += 1;
        st.push({seq[i], dup});
    }
    cout << ans;
    return 0;
}

// 선택한 건물 A, B 사이에 모든 건물이 A, B 높이 이하여야만 한다.
// 만약 건물 A가 건물 B보다 작다면 (A < B) B건물 이후에 나오는 모든 건물에 대해서
// A가 만들 수 있는 쌍은 없다.
// 해당 규칙을 힌트로 이용한다.
