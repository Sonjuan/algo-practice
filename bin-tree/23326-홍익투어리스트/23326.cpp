#include <iostream>
#include <set>

using namespace std;

int N;
int Q;
int t;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<int> table;
    cin >> N >> Q;    

    for(int i = 1; i <= N; ++i) {
        cin >> t;
        if(t)
            table.insert(i);
    }

    int curr = 1;
    while(Q--) {
        cin >> t;
        switch (t) {
            case 1:
                cin >> t;
                if(table.find(t) != table.end())
                    table.erase(t);
                else
                    table.insert(t);
            break;
            case 2:
                cin >> t;
                curr = (curr + t - 1) % N + 1;
            break;
            case 3:
                if(table.empty()) cout << -1 << '\n';
                else {
                    auto it = table.lower_bound(curr);
                    if(it != table.end())
                        cout << *it - curr << '\n';
                    else   
                        cout << N - curr + *table.begin() << '\n';
                }
        }
    }

    return 0;
}