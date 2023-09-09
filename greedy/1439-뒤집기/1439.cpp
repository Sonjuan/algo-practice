#include <iostream>
#include <string>

using namespace std;

string s;

int main(void) {
    cin >> s;

    int bw[2] = {1, 0};
    int color = 0;
    for(int i = 0; i < s.size()-1; ++i) {
        if(s[i] != s[i+1]) {
            color = 1 - color;
            bw[color] += 1;
        }
    }
    
    cout << min(bw[0], bw[1]);

    return 0;
}