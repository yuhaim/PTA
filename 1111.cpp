#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;
struct Edge{
	int id;
	int length;
	int time;
};

int N, M;
int src, dest;
vector<vector<Edge>> graph;
vector<bool> visited;
vector<int> route_trace;

vector<int> shortest_route;
int shortest_d = INT_MAX;
int fastest_td = INT_MAX;
vector<int> fastest_route;
int fastest_t = INT_MAX;
int min_sect = INT_MAX;

void dfs(int root)
{
	route_trace.push_back(root);
	visited[root] = true;

	if(root==dest){
		int temp_d = 0, temp_t = 0;
		for(int i=1; i<route_trace.size(); i++){
			int p = route_trace[i-1];
			int q = route_trace[i];
			int j;
			for(j=0; j<graph[p].size(); j++)
				if(graph[p][j].id == q)
					break;

			temp_d += graph[p][j].length;
			temp_t += graph[p][j].time;
		}

		if(temp_d < shortest_d || 
			(temp_d == shortest_d && temp_t < fastest_td)){
			shortest_d = temp_d;
			fastest_td = temp_t;
			shortest_route = route_trace;
		}

		if(temp_t < fastest_t || 
			(temp_t == fastest_t && route_trace.size() < min_sect)){
			fastest_t = temp_t;
			fastest_route = route_trace; 
			min_sect = route_trace.size();
		}

		route_trace.pop_back();
		visited[root] = false;
		return;
	}

	for(int i=0; i<graph[root].size(); i++){
		if(!visited[graph[root][i].id])
			dfs(graph[root][i].id);
	}

	route_trace.pop_back();
	visited[root] = false;
	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1111.txt", "r", stdin);
#endif

	cin >> N >> M;
	graph.resize(N);
	visited.resize(N);

	for(int i=0; i<M; i++){
		int p, q, d, len, t;
		cin >> p >> q >> d >> len >> t;
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

	cin >> src >> dest;
	fill(visited.begin(), visited.end(), false);
	dfs(src);

	if(shortest_route!=fastest_route){
		cout << "Distance = " << shortest_d << ": "
			 << shortest_route[0];
		for(int i=1; i<shortest_route.size(); i++){
			cout << " -> " << shortest_route[i];
		}
		cout << endl;
		cout << "Time = " << fastest_t << ": "
			 << fastest_route[0];
		for(int i=1; i<fastest_route.size(); i++){
			cout << " -> " << fastest_route[i];
		}
	} else {
		cout << "Distance = " << shortest_d << "; "
			 << "Time = " << fastest_t << ": ";
		cout << shortest_route[0];
		for(int i=1; i<shortest_route.size(); i++){
			cout << " -> " << shortest_route[i];
		}
	}

	return 0;
}