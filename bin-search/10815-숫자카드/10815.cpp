#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& x, int k) {
    int n = x.size();
    int p = 0;

    for(int i = n; i >= 1; i /= 2) {
        while(p+i < n && x[p+i] <= k) p += i;
    }
    return x[p] == k ? 1 : 0;
}

int main(void) {
    int N;
    cin >> N;
    
    vector<int> a(N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    
    int M;
    cin >> M;
    
    vector<int> b(M, 0);
    for(int i = 0; i < M; ++i) {
        cin >> b[i];
    }
    for(int i = 0; i < M; ++i) {
        cout << search(a, b[i]) << ' ';
    }


    return 0;
}
