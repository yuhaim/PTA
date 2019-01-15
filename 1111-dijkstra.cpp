#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

struct Edge{
	int id;
	int length;
	int time;
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1111.txt", "r", stdin);
#endif
	int N, M;
	cin >> N >> M;

	vector<vector<Edge>> graph(N);

	for(int i=0; i<M; i++){
		int p, q, d, len, t;
		//cin >> p >> q >> d >> len >> t;
		scanf("%d%d%d%d%d", &p, &q, &d, &len, &t);
		Edge e;
		e.id = q;
		e.length = len;
		e.time = t;
		graph[p].push_back(e);
		if(d!=1){
			e.id = p;
			graph[q].push_back(e);
		}
	}

	int src, dest;
	cin >> src >> dest;

	vector<bool> included(N, false);
	vector<int> dist(N, INT_MAX);
	vector<int> durat(N, INT_MAX);
	vector<int> path(N, -1);
	dist[src] = 0;
	durat[src] = 0;
	for(;;){
		int min_id=-1, min_value = INT_MAX;
		for(int i=0; i<N; i++){
			if(!included[i] && dist[i]<min_value){
				min_value = dist[i];
				min_id = i;
			}
		}

		if(min_id==-1) break;
		included[min_id] = true;

		for(int i=0; i<graph[min_id].size(); i++){
			Edge adj = graph[min_id][i];
			if(!included[adj.id] && (
				dist[adj.id] > dist[min_id] + adj.length ||
				(dist[adj.id] == dist[min_id] + adj.length && 
				durat[adj.id] > durat[min_id] + adj.time))){
				dist[adj.id] = dist[min_id] + adj.length;
				durat[adj.id] = durat[min_id] + adj.time;
				path[adj.id] = min_id;
			}
		}
	}

	vector<int> shortest;
	int temp = dest;
	while(temp!=-1){
		shortest.push_back(temp);
		temp = path[temp];
	}

	vector<bool> included_time(N, false);
	vector<int> dist_time(N, INT_MAX);
	vector<int> durat_time(N, INT_MAX);
	vector<int> path_time(N, -1);
	dist_time[src] = 0;
	durat_time[src] = 0;
	for(;;){
		int min_id=-1, min_value = INT_MAX;
		for(int i=0; i<N; i++){
			if(!included_time[i] && durat_time[i]<min_value){
				min_value = durat_time[i];
				min_id = i;
			}
		}

		if(min_id==-1) break;
		included_time[min_id] = true;

		for(int i=0; i<graph[min_id].size(); i++){
			Edge adj = graph[min_id][i];
			if(!included_time[adj.id] && (
				durat_time[adj.id] > durat_time[min_id] + adj.time || 
				(durat_time[adj.id] == durat_time[min_id] + adj.time && 
				dist_time[adj.id] > dist_time[min_id] + 1))){
				durat_time[adj.id] = durat_time[min_id] + adj.time;
				dist_time[adj.id] = dist_time[min_id] + 1;			
				path_time[adj.id] = min_id;
			}
		}
	}

	vector<int> fastest;
	int temp_time = dest;
	while(temp_time!=-1){
		fastest.push_back(temp_time);
		temp_time = path_time[temp_time];
	}

	if(shortest != fastest){
		printf("Distance = %d: ", dist[dest]);
		cout << shortest[shortest.size()-1];
		for(int i=shortest.size()-2; i>=0; i--)
			cout << " -> " << shortest[i];

		printf("\nTime = %d: ", durat_time[dest]);
		cout << fastest[fastest.size()-1];
		for(int i=fastest.size()-2; i>=0; i--)
			cout << " -> " << fastest[i];
	} else {
		printf("Distance = %d; Time = %d: ", dist[dest], durat[dest]);
		cout << shortest[shortest.size()-1];
		for(int i=shortest.size()-2; i>=0; i--)
			cout << " -> " << shortest[i];
	}

	return 0;
}