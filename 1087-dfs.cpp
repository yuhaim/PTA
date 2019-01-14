#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;
int N, K;
vector<vector<pair<int, int>>> graph;
vector<int> vertex_weight;
unordered_map<int, string> id2str;
unordered_map<string, int> str2id;
vector<bool> visited;

int num_route = 0;
int min_edge = INT_MAX;
int max_vertex = 0;
double max_average = 0.0;
vector<int> opt_route;
vector<int> route_trace;

void dfs(int root)
{
	route_trace.push_back(root);
	visited[root] = true;

	if(id2str[root] == "ROM"){
		int cost = 0;
		int happiness = 0;
		double average_hp = 0.0;
		for(int i=1; i<route_trace.size(); i++){
			int id = route_trace[i];
			int pre_id = route_trace[i-1];
			int j;
			for(j=0; j<graph[id].size(); j++){
				if(graph[id][j].first == pre_id)
					break;
			}
			cost += graph[id][j].second;
			happiness += vertex_weight[id]; //
		}
		average_hp = (double)happiness/(route_trace.size()-1);

		if(cost < min_edge){
			num_route = 1;
			min_edge = cost;
			max_vertex = happiness;
			max_average = average_hp;
			opt_route = route_trace;
		} else if(cost == min_edge){
			num_route++;
			if(happiness > max_vertex){
				max_vertex = happiness;
				max_average = average_hp;
				opt_route = route_trace;
			} else if(happiness == max_vertex){
				if(average_hp > max_average){
					max_average = average_hp;
					opt_route = route_trace;
				}
			}
		}

		visited[root] = false;
		route_trace.pop_back();
		return; //
	}

	for(int i=0; i<graph[root].size(); i++){
		if(!visited[graph[root][i].first])
			dfs(graph[root][i].first);
	}

	visited[root] = false;
	route_trace.pop_back();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1087.txt", "r", stdin);
#endif
	cin >> N >> K;
	string temp_str;
	cin >> temp_str;
	id2str[0] = temp_str;
	str2id[temp_str] = 0;

	vertex_weight.resize(N);
	for(int i=1; i<=N-1; i++){
		int w;
		cin >> temp_str >> w;
		vertex_weight[i] = w;
		id2str[i] = temp_str;
		str2id[temp_str] = i;
	}

	graph.resize(N);
	for(int i=0; i<K; i++){
		string u, v;
		int w;
		cin >> u >> v >> w;
		graph[str2id[u]].push_back(make_pair(str2id[v], w));
		graph[str2id[v]].push_back(make_pair(str2id[u], w));
	}

	visited.resize(N);
	fill(visited.begin(), visited.end(), false);
	dfs(0);

	cout << num_route << ' ' 
		 << min_edge << ' ' 
		 << max_vertex << ' ' 
		 << (int)max_average << endl;

	cout << id2str[opt_route[0]];
	for(int i=1; i<opt_route.size(); i++){
		cout << "->" << id2str[opt_route[i]];
	}

	return 0;
}