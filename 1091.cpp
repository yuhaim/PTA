#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

struct pos {
	int i, j, k;
};

pos make_pos(int i, int j, int k)
{
	pos p;
	p.i = i;
	p.j = j;
	p.k = k;
	return p;
}

struct pixel {
	int stroke;
	bool visited;
};

int M, N, L, T;
vector<vector<vector<pixel>>> scan;

bool is_valid(const pos &p)
{
	if (p.i<0 || p.i >= L || p.j<0 || p.j >= M || p.k<0 || p.k >= N)
		return false;
	if (scan[p.i][p.j][p.k].visited || scan[p.i][p.j][p.k].stroke == 0)
		return false;
	return true;
}

void push_visit(queue<pos> &q, const pos &p)
{
	q.push(p);
	scan[p.i][p.j][p.k].visited = true;
}

void bfs(const pos &p, int &volume)
{
	queue<pos> q;
	push_visit(q, p);

	while (!q.empty()) {
		pos temp;
		temp = make_pos( q.front().i - 1, q.front().j, q.front().k );
		if (is_valid(temp)) push_visit(q, temp);
		temp = make_pos( q.front().i + 1, q.front().j, q.front().k );
		if (is_valid(temp)) push_visit(q, temp);
		temp = make_pos( q.front().i, q.front().j - 1, q.front().k );
		if (is_valid(temp)) push_visit(q, temp);
		temp = make_pos( q.front().i, q.front().j + 1, q.front().k );
		if (is_valid(temp)) push_visit(q, temp);
		temp = make_pos( q.front().i, q.front().j, q.front().k - 1 );
		if (is_valid(temp)) push_visit(q, temp);
		temp = make_pos( q.front().i, q.front().j, q.front().k + 1 );
		if (is_valid(temp)) push_visit(q, temp);

		volume++;
		q.pop();
	}

	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1091.txt", "r", stdin);
#endif

	cin >> M >> N >> L >> T;

	scan.resize(L);
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
				if (is_valid(make_pos( i,j,k)))
					bfs(make_pos( i,j,k), volume);
				if(volume>=T)
					total_volume += volume;
			}
		}
	}

	cout << total_volume << endl;

	return 0;
}