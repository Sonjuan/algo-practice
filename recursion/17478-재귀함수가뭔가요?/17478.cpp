#include <bits/stdc++.h>
using namespace std;
int N;
void _bar(const char* str, int stk) {
    for(int j = 0; j < stk; ++j) cout << "___";
    cout << str;
}

void solve(int cnt) {
    _bar("\"재귀함수가 뭔가요?\"\n", cnt);
    if(cnt == N) _bar("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", cnt);
    else {
        _bar("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", cnt);

        solve(cnt+1);
    }
    _bar("라고 답변하였지.\n", cnt);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    solve(0);
}
