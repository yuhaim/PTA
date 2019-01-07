#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool check(const vector<int> &order, const vector<vector<int>> &graph, vector<int> in_degree)
{
	for(int i=0; i<order.size(); i++){
		int k = order[i];
		if(in_degree[k]>0) return false;
		else if(in_degree[k]==0){
			for(int j=0; j<graph[k].size(); j++){
				in_degree[graph[k][j]]--;
			}
		}
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1146.txt", "r", stdin);
#endif

	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N+1);
	vector<int> in_degree(N+1);

	for(int i=0; i<M; i++){
		int p, q;
		cin >> p >> q;
		graph[p].push_back(q);
		in_degree[q]++;
	}

	int K;
	cin >> K;
	vector<int> ans;
	for(int i=0; i<K; i++){
		vector<int> order(N);
		for(int j=0; j<N; j++)
			cin >> order[j];

		if(!check(order, graph, in_degree))
			ans.push_back(i);
	}

	bool init = true;
	for(int i=0; i<ans.size(); i++){
		if(init)
			init = false;
		else
			cout << ' ';
		cout << ans[i];
	}

	return 0;
}