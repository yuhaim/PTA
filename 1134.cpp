#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1134.txt", "r", stdin);
#endif

	int N, M;
	cin >> N >> M;

	vector<vector<int>> vertex(N);
	for(int i=0; i<M; i++){
		int p, q;
		cin >> p >> q;
		vertex[p].push_back(i);
		vertex[q].push_back(i);
	}

	int K;
	cin >> K;
	for(int i=0; i<K; i++){
		int Nv;
		cin >> Nv;
		vector<bool> edges_visited(M, false);
		for(int j=0; j<Nv; j++){
			int p;
			cin >> p;
			for(int k=0; k<vertex[p].size(); k++){
				edges_visited[vertex[p][k]] = true;
			}
		}
		
		int j;
		for(j=0; j<M; j++){
			if(edges_visited[j]==false){
				break;
			}
		}

		if(j==M)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}