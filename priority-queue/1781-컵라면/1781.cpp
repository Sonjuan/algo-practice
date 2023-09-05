#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int N, dl, cn;
    unsigned int cupNoodles = 0;
    priority_queue<unsigned int> cn_candidate;
    vector<vector<unsigned int>> cn_by_deadline(200'002);

    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> dl >> cn;
        cn_by_deadline[dl].push_back(cn);
    }
    for(int cur = 200'001; cur != 0; cur--) {
        for(int noodle : cn_by_deadline[cur]) {
            cn_candidate.push(noodle);
        }

        if(cn_candidate.empty()) continue;

        cupNoodles += cn_candidate.top();
        cn_candidate.pop();
    }
    
    cout << cupNoodles;

    return 0;
}
