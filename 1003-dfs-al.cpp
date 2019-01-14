#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int N, M, C1, C2;
vector<int> v_weight;
vector<vector<pair<int, int>>> graph;
int num_route = 0;
int sum_edge = INT_MAX;
int sum_vertex = 0;
vector<int> vertex_trace;
vector<bool> visited; 

void dfs(int root)
{
	vertex_trace.push_back(root);
	visited[root] = true;

	if(root == C2){
		int sum_v_temp = v_weight[C1];
		int sum_e_temp = 0;

		for(int i=1; i<vertex_trace.size(); i++){
			sum_v_temp += v_weight[vertex_trace[i]];
			int j;
			for(j=0; j<graph[vertex_trace[i-1]].size(); j++){
				if(vertex_trace[i] == graph[vertex_trace[i-1]][j].first)
					break;
			}
			sum_e_temp += graph[vertex_trace[i-1]][j].second;
		}

		if(sum_e_temp < sum_edge){
			sum_edge = sum_e_temp;
			num_route = 1;
			sum_vertex = sum_v_temp;
		} else if(sum_e_temp==sum_edge){
			num_route++;
			if(sum_v_temp > sum_vertex){
				sum_vertex = sum_v_temp;
			}
		}

		visited[root] = false;
		vertex_trace.pop_back();
		return;
	}

	for(int i=0; i<graph[root].size(); ++i){
		if(!visited[graph[root][i].first])
			dfs(graph[root][i].first);
	}

	visited[root] = false;
	vertex_trace.pop_back();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1003.txt", "r", stdin);
#endif

	cin >> N >> M >> C1 >> C2;

	v_weight.resize(N);
	for(int i=0; i<N; i++)
		cin >> v_weight[i];

	graph.resize(N);
	for(int i=0; i<M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	visited.resize(N);
	fill(visited.begin(), visited.end(), false);
	dfs(C1);

	cout << num_route << ' ' << sum_vertex << endl;

	return 0;
}