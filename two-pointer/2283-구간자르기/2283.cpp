#include <iostream>

using namespace std;

int N;
int K;
int arr[1000005];

int main(void) {
    cin >> N >> K;

    for(int i = 0 ; i < N; ++i) {
        int l,r;
        cin >> l >> r;
        arr[l+1] += 1;
        arr[r+1] -= 1;
    }

    for(int i = 1; i <= 1000000; ++i) {
        arr[i] += arr[i-1];
    }

    int left  = 0;
    int right = 0;        
    int sum = 0;

    while(true) {
        if(sum < K) {
            sum += arr[++right];
        }else if(sum > K) {
            sum -= arr[++left];
        }else{
            cout << left << " " << right;
            return 0;
        }
        
        if(right == 1000001){
            break;
        }
    }

    cout << "0 0";

    return 0;
}