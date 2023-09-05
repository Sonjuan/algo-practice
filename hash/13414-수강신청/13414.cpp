#include <iostream>
#include <vector>
#include <set>

using namespace std;

int K;
int L;
vector<string> seq;

int main(void) {
    set<string> s;
    cin >> K >> L;

    for(int i = 0; i < L; ++i) {
        string temp;
        cin >> temp;
        seq.push_back(temp);
    }

    for(int i = seq.size()-1; i >= 0; i--) {
        if(s.find(seq[i]) == s.end()) {
            s.insert(seq[i]);
        }else {
            seq[i] = "x";
        }
    }
    
    for(int i = 0; i < seq.size() && K != 0; ++i) {
        if(seq[i] == "x") continue;
        cout << seq[i] << '\n';
        K--;
    }


    return 0;
}