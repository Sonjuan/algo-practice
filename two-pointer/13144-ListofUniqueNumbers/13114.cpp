#include <iostream>

using namespace std;

int N;
int table[100005];
int visited[100005];

int main(void) {
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> table[i];
    }
    
    visited[table[0]] = 1;
    int en = 0;
    long long ans = 0;
    for(int st = 0; st < N; ++st) {
        while(en < N-1 && !visited[table[en+1]]) {
            en++;
            visited[table[en]] = 1;
        }
        ans += (en-st+1);
        visited[table[st]] = 0;
    }
    
    cout << ans;
    return 0;
}
