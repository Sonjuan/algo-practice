#include <iostream>
#include <vector>
using namespace std;

int T;
int N;

int main(void) {
    cin >> T;
    while(T--) {
        cin >> N;
        vector<int> seq(N, 0);
        for(int i= 0; i < N; ++i)  cin >> seq[i];
        
        int MAX = -1;
        long long res = 0;

        for(int i = N-1; i >= 0; --i) {
            if(MAX < seq[i]) MAX = seq[i];
            res += (MAX - seq[i]);
        }

        cout << res << endl;
    }
    return 0;
}