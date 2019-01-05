#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct pixel{
	char stroke;
	bool visited;
};

pixel scan[65][1300][130];

int M, N, L, T;
void dfs(int i, int j, int k, int &volume)
{
	if(i<0 || i>=L || j<0 || j>=M || k<0 || k>=N)
		return;

	if(scan[i][j][k].visited || scan[i][j][k].stroke==0)
		return;

	volume++;
	scan[i][j][k].visited = true;

	dfs(i+1, j, k, volume);
	dfs(i, j+1, k, volume);
	dfs(i, j, k+1, volume);
	dfs(i-1, j, k, volume);
	dfs(i, j-1, k, volume);
	dfs(i, j, k-1, volume);

	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1091.txt", "r", stdin);
#endif

	cin >> M >> N >> L >> T;

	for(int i=0; i<L; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<N; k++){
				scanf("%d", &scan[i][j][k].stroke);
				scan[i][j][k].visited = false;
			}
		}
	}

	int total_volume = 0;
	for(int i=0; i<L; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<N; k++){
				int volume = 0;
				if(!scan[i][j][k].visited && scan[i][j][k].stroke==1) //
					dfs(i, j, k, volume);
				if(volume>=T)
					total_volume += volume;
			}
		}
	}

	cout << total_volume << endl;

	return 0;
}