#include <iostream>
#include <unordered_map>

using namespace std;

long long N;
int P;
int Q;
unordered_map<long, long> table;

// Too big N
long long solve(long long K) {
    if(K == 0) return 1;
    if(table.find(K) != table.end()) return table[K];

    table[K] = solve(K / P) + solve(K / Q);
    return table[K];
}

int main(void) {
    cin >> N >> P >> Q;
    cout << solve(N) << endl;
    // cout << table[N]; Potential insight in input: 0 2 2

    return 0;
}