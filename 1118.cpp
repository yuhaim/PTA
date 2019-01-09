#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Family{
	int parent;
	bool visited;
};

vector<Family> F;

int Find(int id)
{
	return F[id].parent<0 ? id : F[id].parent=Find(F[id].parent);
}

void Union(int id_x, int id_y)
{
	int x = Find(id_x);
	int y = Find(id_y);
	if(F[x].parent <= F[y].parent){
		F[x].parent += F[y].parent;
		F[y].parent = x;
	}else if(F[y].parent < F[x].parent){
		F[y].parent += F[x].parent;
		F[x].parent = y;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1118.txt", "r", stdin);
#endif

	int N;
	cin >> N;
	Family f_init = {-1, false};
	F.resize(10001, f_init);

	for(int i=0; i<N; i++){
		int K;
		cin >> K;
		int B0;
		cin >> B0;
		F[B0].visited = true;
		for(int j=1; j<K; j++){
			int B;
			cin >> B;
			F[B].visited = true;
			Union(B0, B);
		}
	}

	int trees = 0, birds = 0;
	for(int i=1; i<=10000; i++){
		if(F[i].visited && F[i].parent<0){
			trees++;
			birds+= -F[i].parent;
		}
	}
	cout << trees << ' ' << birds << endl;

	int Q;
	cin >> Q;
	for(int i=0; i<Q; i++){
		int p, q;
		cin >> p >> q;
		if(Find(p)==Find(q))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}