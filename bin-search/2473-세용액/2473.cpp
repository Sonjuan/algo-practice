#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int table[5000];

int bin_search(int st, long long k) {
    int q = st+1;
    for (int a = N; a >= 1; a /= 2) {
        while (q+a < N && table[q+a] <= k) q += a;
    }

    if(q != N-1) {
        return (abs(table[q] - k) < abs(table[q+1]) - k) ? q : q+1;
    }
    return q;
}

int main(void) {
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> table[i];
    }
    
    sort(table, table+N);
    
    long long tick = 3000000001;
    int a=0,b=1,c=2;
    
    for(int i = 0; i < N-2; ++i) {
        for(int j = i+1; j < N-1; ++j) {
            int k = bin_search(j, -(table[i] + table[j]));
            long long temp = (long long)table[i] + (long long)table[j] + (long long)table[k];

            if(abs(temp) < abs(tick)) {
                a = i; 
                b = j;
                c = k;
                tick = temp;
            }
        }
    }
    
    cout << table[a] << " " << table[b] << " " << table[c];
    
    return 0;
}
