#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int max_level, max_count;
void dfs(int root, int level, const vector<vector<int>> &graph)
{
	if(graph[root].size()==0){
		if(level>max_level){
			max_level = level;
			max_count = 1;
		} else if(level==max_level){
			max_count++;
		}
	}

	for(int i=0; i<graph[root].size(); i++){
		dfs(graph[root][i], level+1, graph);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1090.txt" , "r", stdin);
#endif

	int N;
	double P, r;
	cin >> N >> P >> r;

	vector<vector<int>> graph(N);
	int root;
	for(int i=0; i<N; i++){
		int temp;
		scanf("%d", &temp);
		if(temp==-1)
			root = i;
		else
			graph[temp].push_back(i);
	}

	dfs(root, 0, graph);

	printf("%.2f %d\n", P*pow((1.0+r*0.01), max_level), max_count);

	return 0;
}