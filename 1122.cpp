#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int graph[205][205];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1122.txt", "r", stdin);
#endif

	int N, M;
	cin >> N >> M;

	for(int i=0; i<M; i++){
		int p, q;
		cin >> p >> q;
		graph[p][q] = 1;
		graph[q][p] = 1;
	}

	int K;
	cin >> K;
	for(int i=0; i<K; i++){
		bool flag = true;
		int n;
		cin >> n;
		vector<int> vertex_visited(N+1, 0);

		int start, curr;
		cin >> start;
		curr = start;
		for(int j=1; j<n; j++){
			int p;
			cin >> p;
			if(graph[curr][p]==0 || (j==n-1 && p!=start)){
				flag=false;
				//break;
			} 

			vertex_visited[p]++;
			curr = p;
		}
		
		for(int j=1; j<=N; j++){
			if(vertex_visited[j]!=1){
				flag = false;
				break;
			}
		}

		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}