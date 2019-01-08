#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1126.txt", "r", stdin);
#endif

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N+1);
	for(int i=0; i<M; i++){
		int p, q;
		cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}

	bool init = true;
	int count = 0;
	for(int i=1; i<=N; i++){
		if(init)
			init = false;
		else
			cout << ' ';

		if(graph[i].size()%2)
			count++;

		cout << graph[i].size();
	}
	
	cout << endl;

	vector<bool> visited(N+1, false);
	queue<int> que;
	que.push(1);
	visited[1] = true;

	while(!que.empty()){
		int k = que.front();
		que.pop();
		for(int i=0; i<graph[k].size(); i++){
			if(!visited[graph[k][i]]){
				que.push(graph[k][i]);
				visited[graph[k][i]] = true;
			}
		}
	}

	bool has_isolated = false;
	for(int i=1; i<=N; i++){
		if(!visited[i])
			has_isolated = true;
	}

	if(count == 0 && !has_isolated)
		cout << "Eulerian";
	else if(count == 2 && !has_isolated)
		cout << "Semi-Eulerian";
	else
		cout << "Non-Eulerian";

	return 0;
}