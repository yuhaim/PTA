#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int min_level=999999999, min_count;

void dfs(int root, int level, const vector<vector<int>> &chain)
{
	if(chain[root].size()==0){
		if(level < min_level){
			min_level = level;
			min_count = 1;
		} else if(level == min_level){
			min_count++;
		}
		return;
	}
		
	for(int i=0; i<chain[root].size(); i++){
		dfs(chain[root][i], level+1, chain);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1106.txt", "r", stdin);
#endif

	int N;
	double P, r;
	cin >> N >> P >> r;

	vector<vector<int>> chain(N);

	for(int i=0; i<N; i++){
		int n_child;
		cin >> n_child;
		chain[i].resize(n_child);
		for(int j=0; j<n_child; j++){
			cin >> chain[i][j];
		}
	}

	dfs(0, 0, chain);

	for(int i=0; i<min_level; i++){
		P *= 1.0 + 0.01*r;
	}

	printf("%.4f %d\n", P, min_count);
	return 0;
}