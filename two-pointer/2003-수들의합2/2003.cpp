#include <iostream>

using namespace std;

int N;
int M;
int table[10005];

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        cin >> table[i];
    }
    
    int s = 0;
    int e = 1;
    int temp = table[0];
    int ans = 0;

    while(1) {
        if(temp == M) ans++;
        if(temp <= M) temp += table[e++];
        if(temp >  M) temp -= table[s++];
        if(e > N) break;
    }

    cout << ans;
    
    return 0;
}
