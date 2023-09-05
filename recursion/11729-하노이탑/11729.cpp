#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n) {
    if(n==1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    func(6-a-b, b, n-1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    cout << (1<<k) - 1 << '\n';
    func(1, 3, k);
}

// To move plates
// 1 3 3
// is equal to
// 1 2 2
// 1 3 -
// 2 3 2