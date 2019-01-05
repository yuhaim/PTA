#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

vector<int> level;
void dfs(int root, int curr_level, const vector<vector<int>> &tree)
{
	level[root] = curr_level;
	if(tree[root].size()==0)
		return;
	for(int i=0; i<tree[root].size(); i++){
		dfs(tree[root][i], curr_level+1, tree);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1094.txt", "r", stdin);
#endif

	int N, M;
	cin >> N >> M;
	vector<vector<int>> tree(N+1);
	level.resize(N+1);

	for(int i=0; i<M; i++){
		int id, n_child;
		cin >> id >> n_child;
		for(int j=0; j<n_child; j++){
			int temp;
			cin >> temp;
			tree[id].push_back(temp);
		}
	}

	dfs(1, 1, tree);

	map<int, int> map_count;
	for(int i=1; i<=N; i++){
		map_count[level[i]]++;
	}

	int max_population = 0;
	int max_level;
	for(auto iter = map_count.begin(); iter!=map_count.end(); iter++){
		if(iter->second > max_population){
			max_population = iter->second;
			max_level = iter->first;
		}
	}

	cout << max_population << ' ' << max_level << endl;
	return 0;
}