#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1143.txt", "r", stdin);
#endif

	int M, N;
	cin >> M >> N;

	vector<int> pre_list(N);
	unordered_set<int> set_elem;
	for(int i=0; i<N; i++){
		cin >> pre_list[i];
		set_elem.insert(pre_list[i]);
	}

	for(int i=0; i<M; i++){
		int U, V, A;
		cin >> U >> V;

		if(set_elem.count(U)==0 && set_elem.count(V)==0){
			printf("ERROR: %d and %d are not found.\n", U, V);
			continue;
		}

		if(set_elem.count(U)==0){
			printf("ERROR: %d is not found.\n", U);
			continue;
		}

		if(set_elem.count(V)==0){
			printf("ERROR: %d is not found.\n", V);
			continue;
		}

		for(int i=0; i<N; i++){
			A = pre_list[i];
			if((A>=U && A<=V) || (A>=V && A<=U))
				break;
		}

		if(A==U){
			printf("%d is an ancestor of %d.\n", U, V);
		} else if(A==V){
			printf("%d is an ancestor of %d.\n", V, U);
		} else {
			printf("LCA of %d and %d is %d.\n", U, V, A);
		}
	}

	return 0;
}