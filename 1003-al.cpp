#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1003.txt", "r", stdin);
#endif

	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;

	vector<int> v_weight(N);
	for(int i=0; i<N; i++)
		cin >> v_weight[i];

	vector<vector<pair<int, int>>> graph(N);
	for(int i=0; i<M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	vector<int> dist(N, INT_MAX);
	vector<bool> included(N, false);
	vector<int> num_route(N, 0);
	vector<int> sum_weight(N, 0);

	dist[C1] = 0;
	//included[C1] = true; // init in relaxation
	num_route[C1] = 1;
	sum_weight[C1] = v_weight[C1];

	//for(int i=0; i<N; i++){
	for( ; ; ){ // possibly not connected
		int u = -1, d_min = INT_MAX;
		for(int j=0; j<N; j++){
			if(included[j]==false && dist[j]<d_min){
				u = j;
				d_min = dist[j];
			}
		}

		if(u == -1) break; // possibly not connected
		included[u] = true;

		for(int j=0; j<graph[u].size(); j++){
			int index = graph[u][j].first;
			int weight = graph[u][j].second;
			if(included[index]==false){
				if(dist[index] > dist[u] + weight){
					dist[index] = dist[u] + weight;
					num_route[index] = num_route[u];
					sum_weight[index] = sum_weight[u] + v_weight[index];
				} else if(dist[index] == dist[u] + weight){
					num_route[index] += num_route[u];
					if(sum_weight[index] < sum_weight[u] + v_weight[index]){
						sum_weight[index] = sum_weight[u] + v_weight[index];
					}
				}
			}
		}
	}

	cout << num_route[C2] << ' ' << sum_weight[C2] << endl;

	return 0;
}