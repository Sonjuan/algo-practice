#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    vector<int> arr(N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for(int i = 1; i < N; ++i) {
        arr[i] = max(arr[i], arr[i]+arr[i-1]);
    }
    
    cout << *max_element(arr.begin(), arr.end());


    return 0;
}
