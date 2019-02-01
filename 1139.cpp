#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

void query(const string &str_src, const string &str_dest, 
			const vector<vector<int>> &graph,
			unordered_map<int, bool> &gender,
			vector<pair<int, int>> &result)
{
	int src, dest;
	bool gender_src, gender_dest;
	if(str_src[0]=='-'){
		src = stoi(str_src.substr(1));
		gender_src = true;
	}else{
		src = stoi(str_src);
		gender_src = false;
	}
	if(str_dest[0]=='-'){
		dest = stoi(str_dest.substr(1));
		gender_dest = true;
	}else{
		dest = stoi(str_dest);
		gender_dest = false;
	}

	if(!gender.count(src) || !gender.count(dest))
		return;

	if(gender[src]!=gender_src || gender[dest]!=gender_dest)
		return;

	for(int i=0; i<graph[src].size(); i++){
		int adj_1 = graph[src][i];
		if(gender[adj_1] == gender[src] && adj_1!=dest){
			for(int j=0; j<graph[adj_1].size(); j++){
				int adj_2 = graph[adj_1][j];
				if(gender[adj_2]==gender[dest] && adj_2!=src){
					for(int k=0; k<graph[adj_2].size(); k++){
						if(dest == graph[adj_2][k]){
							result.push_back(make_pair(adj_1, adj_2));
						}
					}
				}
			}
		}
	}
}

void print(const vector<pair<int, int>> &result)
{
	cout << result.size() << endl;
	for(int i=0; i<result.size(); i++){
		printf("%04d %04d\n", result[i].first, result[i].second);
	}
}

bool cmp(const pair<int, int> &x, const pair<int, int> &y)
{
	return x.first == y.first ? x.second < y.second : x.first < y.first;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1139.txt", "r", stdin);
#endif
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(10000);
	unordered_map<int, bool> gender;
	for(int i=0; i<M; i++){
		string str_p, str_q;
		cin >> str_p >> str_q;
		int p, q;
		
		if(str_p[0]=='-'){
			p = stoi(str_p.substr(1));
			gender[p] = true;
		}else{
			p = stoi(str_p);
			gender[p] = false;
		}
		if(str_q[0]=='-'){
			q = stoi(str_q.substr(1));
			gender[q] = true;
		}else{
			q = stoi(str_q);
			gender[q] = false;
		}
		graph[p].push_back(q);
		graph[q].push_back(p);
	}

	int K;
	cin >> K;
	for(int i=0; i<K; i++){
		string str_src, str_dest;
		cin >> str_src >> str_dest;
		vector<pair<int, int>> result;
		query(str_src, str_dest, graph, gender, result);
		sort(result.begin(), result.end(), cmp);
		print(result);
	}

	return 0;
}