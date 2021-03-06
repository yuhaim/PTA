#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;
int graph[500][500];
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

	fill(graph[0], graph[0]+500*500, INT_MAX); // 
	for(int i=0; i<M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v] = w;
		graph[v][u] = w;
	}

	vector<int> dist(N, INT_MAX);
	vector<bool> included(N, false);
	vector<int> num_route(N, 0);
	vector<int> sum_weight(N, 0);

	dist[C1] = 0;
	//visited[C1] = true;
	num_route[C1] = 1;
	sum_weight[C1] = v_weight[C1];

	for(int i=0; i<N; i++){
		int u = -1, d_min = INT_MAX;
		for(int j=0; j<N; j++){
			if(included[j]==false && dist[j]<d_min){
				u = j;
				d_min = dist[j];
			}
		}

		//if(u == -1) break;
		included[u] = true;

		for(int j=0; j<N; j++){
			if(graph[u][j]<INT_MAX && included[j]==false){
				if(dist[j] > dist[u] + graph[u][j]){
					dist[j] = dist[u] + graph[u][j];
					num_route[j] = num_route[u];
					sum_weight[j] = sum_weight[u] + v_weight[j];
				} else if(dist[j] == dist[u] + graph[u][j]){
					num_route[j] += num_route[u];
					if(sum_weight[j] < sum_weight[u] + v_weight[j]){
						sum_weight[j] = sum_weight[u] + v_weight[j];
					}
				}
			}
		}
	}

	cout << num_route[C2] << ' ' << sum_weight[C2] << endl;

	return 0;
}