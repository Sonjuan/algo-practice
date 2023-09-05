#include <iostream>

using namespace std;

int DP[1001] = {0, 1, 3};

int f(int n) {
    if(DP[n]) return DP[n];
    return DP[n] = (f(n-1) %10007 + 2*f(n-2) %10007) %10007;
}

int main(void) {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
