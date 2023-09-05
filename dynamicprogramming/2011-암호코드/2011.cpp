#include <iostream>
#include <string>
using namespace std;

int a[5001];
int d[5001];
int N;
int mod = 1000000;

int main(void) {
    string s;
    cin >> s;

    N = s.size();

    for(int i = 1; i <= N; ++i) {
        a[i] = s[i -1] - '0'; 
    }
    d[0] = 1;

    for(int i = 1; i <= N; ++i) {
        if(a[i] > 0) {
            d[i] = (d[i]+d[i-1]) % mod;
        }
        int x = a[i-1]*10 + a[i];
        if(x >= 10 && x <= 26) {
            d[i] = (d[i] + d[i-2]) % mod;
        }
    }
    cout << d[N];

    return 0;
}
