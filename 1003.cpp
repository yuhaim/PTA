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

	fill(graph[0], graph[0]+500*500, INT_MAX);
	for(int i=0; i<M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v] = w;
		graph[v][u] = w;
	}

	vector<int> dist(N, INT_MAX);
	vector<int> path(N, -1);
	vector<bool> visited(N, false);
	dist[C1] = 0;
	//visited[C1] = true;

	for(int i=0; i<N; i++){
		int u = -1, d_min = INT_MAX;
		for(int j=0; j<N; j++){
			if(visited[j]==false && dist[j]<d_min){
				u = j;
				d_min = dist[j];
			}
		}

		if(u == -1) break;
		visited[u] = true;

		for(int j=0; j<N; j++){
			if(graph[u][j]<INT_MAX && visited[j]==false){
				if(dist[j] > dist[u] + graph[u][j]){
					dist[j] = dist[u] + graph[u][j];
					path[j] = u;
				}
			}
		}
	}

	int sp = INT_MAX, sp_count = 0;
	for(int i=0; i<N; i++){
		if(i==C1) continue;
		if(dist[i] < sp) {
			sp = dist[i];
			sp_count = 1;
		} else if(dist[i]==sp){
			sp_count++;
		}
	}

	int mw = 0;
	for(int i=0; i<N; i++){
		int m = 0;
		if(sp==dist[i]){
			int temp = i;
			while(temp!=-1){
				m += v_weight[temp];
				temp = path[temp];
			}
		}

		if(m > mw) mw = m;
	}

	return 0;
}