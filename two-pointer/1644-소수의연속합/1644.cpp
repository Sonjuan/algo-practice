#include <iostream>
#include <vector>
using namespace std;

int MAX = 4000005;

int main(void) {
    int N;
    cin >> N;
    
    vector<bool> seive(MAX, true);
    vector<int> table;

    for(int i = 2; i * i < MAX; ++i) {
        if(!seive[i]) continue;
        for(int j = i*i; j < MAX; j += i) {
            seive[j] = false;
        }
    }
    for(int i = 2; i < MAX; ++i) {
        if(seive[i]) table.push_back(i);
    }
    table.push_back(0);

    int ans = 0;
    int s = 0;
    int e = 1;
    int temp = table[0];

    while(1) {
        if(temp == N) ans++;
        if(temp <= N) temp += table[e++];
        if(temp >  N) temp -= table[s++];
        if(e == table.size()) break;
    }


    cout << ans;

    return 0;
}
