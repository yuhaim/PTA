#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct pixel{
	int stroke;
	bool visited;
};

int M, N, L, T;
void dfs(int i, int j, int k, 
			int &volume, vector<vector<vector<pixel>>> &scan)
{
	if(i<0 || i>=L || j<0 || j>=M || k<0 || k>=N)
		return;

	if(scan[i][j][k].visited || scan[i][j][k].stroke==0)
		return;

	volume++;
	scan[i][j][k].visited = true;

	dfs(i+1, j, k, volume, scan);
	dfs(i, j+1, k, volume, scan);
	dfs(i, j, k+1, volume, scan);
	dfs(i-1, j, k, volume, scan);
	dfs(i, j-1, k, volume, scan);
	dfs(i, j, k-1, volume, scan);

	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1091.txt", "r", stdin);
#endif

	cin >> M >> N >> L >> T;

	vector<vector<vector<pixel>>> scan(L);
	for(int i=0; i<L; i++){
		scan[i].resize(M);
		for(int j=0; j<M; j++){
			scan[i][j].resize(N);
			for(int k=0; k<N; k++){
				cin >> scan[i][j][k].stroke;
				scan[i][j][k].visited = false;
			}
		}
	}

	int total_volume = 0;
	for(int i=0; i<L; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<N; k++){
				int volume = 0;
				if(!scan[i][j][k].visited)
					dfs(i, j, k, volume, scan);
				if(volume>=T)
					total_volume += volume;
			}
		}
	}

	cout << total_volume << endl;

	return 0;
}