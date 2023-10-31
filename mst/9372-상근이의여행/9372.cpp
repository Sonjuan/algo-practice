#include <iostream>

using namespace std;

int T,N,M;

int main(void) {
    cin >> T;
    while(T--) {
        cin >> N >> M;
        for(int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
        }
        cout << N-1 << endl;
    }
    return 0;
}