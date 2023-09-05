#include <iostream>
#include <set>

using namespace std;

int h[250005];
int N;
set<int> s;
long long ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    h[0] = 0;
    s.insert(0);
    h[N+1] = 0;
    s.insert(N+1);

    N--;
    int a;
    cin >> a;
    a++;
    h[a] = 1;
    s.insert(a);
    ans = 1;

    while(N--) {
        cin >> a;
        a++;
        auto it = s.lower_bound(a);
        h[a] = max(h[*prev(it)], h[*it]) + 1;
        s.insert(a);
        ans += h[a];
    }    
    cout << ans;


    return 0;
}
