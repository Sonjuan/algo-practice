#include <iostream>
#include <unordered_map>

using namespace std;

int T;
int N;
unordered_map<string, int> table;

int main(void) {
    cin >> T;
    while(T--) {
        cin >> N;
        
        for(int i = 0; i < N; ++i) {
            string L, R;
            cin >> L >> R;
            if(table.find(R) == table.end()) 
                table.insert({R, 1});
            else                             
                table[R]++;
        }

        if(table.empty()) {
            cout << 0 << endl;
            continue;
        }

        int res = 1;
        for(auto t : table)
            res *= (t.second+1);

        cout << res -1 << endl;
        table.clear();
    }


    return 0;
}