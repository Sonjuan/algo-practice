
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main (){

	// 1부터 6까지 담을 벡터
	vector<int> n;

	// 1부터 6까지 생성
	for(int i=0; i<6; i++){
		n.push_back(i+1);
	}

	// 0과1을 저장 할 벡터 생성
	vector<int> ind;

	// k=4, 4개를 뽑으니까
	int k = 4;

	// k개의 1 추가
	for(int i=0; i<k; i++){
		ind.push_back(1);
	}

	// 2개(6개-2개)의 0 추가
	for(int i=0; i<n.size()-k; i++){
		ind.push_back(0);
	}

	// 정렬
	sort(ind.begin(), ind.end());
    int ans = 0;
	//순열
    

	do{
        for(auto i : ind) {
        cout << i ;
        }
        cout << endl;
        ans++;

	}while(next_permutation(ind.begin(), ind.end()));
    cout << ans;
	return 0;
}