#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;
int Find(int x, vector<int> &p)
{
	return p[x] >= 0 ? p[x] = Find(p[x], p) : x;
}

void Union(int x, int y, vector<int> &p)
{
	int p1 = Find(x, p);
	int p2 = Find(y, p);
	if(p[p1]<=p[p2]){
		p[p1] = p[p1] + p[p2];
		p[p2] = p1;
	} else {
		p[p2] = p[p1] + p[p2];
		p[p1] = p2;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1107.txt", "r", stdin);
#endif

	int N;
	cin >> N;
	vector<int> p(N, -1);

	unordered_map<int, vector<int>> h_map;
	for(int i=0; i<N; i++){
		int K, h;
		scanf("%d:", &K);
		while(K--){
			cin >> h;
			for(int j=0;j<h_map[h].size();j++){
				Union(i, h_map[h][j], p);
			}
			h_map[h].push_back(i);
		}
	}

	vector<int> cluster;
	for(int i=0; i<N; i++){
		if(p[i]<0){
			cluster.push_back(-p[i]);
		}
	}

	return 0;
}