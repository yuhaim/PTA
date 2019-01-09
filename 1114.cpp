#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

struct Family{
	int parent;
	int sites;
	int area;
	bool visited;
};

struct Rank{
	int id;
	Family F;
};

struct Rule{
	bool operator()(const Rank &x, const Rank &y){
		if(fabs(x.F.area/(-1.0*x.F.parent) - y.F.area/(-1.0*y.F.parent))<1e-3)
			return x.id < y.id;
		else
			return x.F.area/(-1.0*x.F.parent) > y.F.area/(-1.0*y.F.parent);
	}
};

int Find(int id, vector<Family> &F)
{
	return F[id].parent<0 ? id : F[id].parent = Find(F[id].parent, F);
}

void Union(int x, int y, vector<Family> &F)
{
	int fx = Find(x, F);
	int fy = Find(y, F);
	if(fx < fy){
		F[fx].parent += F[fy].parent;
		F[fx].sites += F[fy].sites;
		F[fx].area += F[fy].area;
		F[fy].sites = 0;
		F[fy].area = 0;
		F[fy].parent = fx;
	}
	else if(fy < fx){
		F[fy].parent += F[fx].parent;
		F[fy].sites += F[fx].sites;
		F[fy].area += F[fx].area;
		F[fx].sites = 0;
		F[fx].area = 0;
		F[fx].parent = fy;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1114.txt", "r", stdin);
#endif
	int N;
	cin >> N;

	Family f_init = {-1, 0, 0, false};
	vector<Family> F(10000, f_init);
	for(int i=0; i<N; i++){
		int id, f_id, m_id;
		cin >> id >> f_id >> m_id;
		F[id].visited = true;
		int k;
		cin >> k;
		vector<int> child(k);
		for(int j=0; j<k; j++){
			cin >> child[j];
			F[child[j]].visited = true;
		}
		int sites, area;
		cin >> sites >> area;

		if(f_id != -1){
			F[f_id].visited = true;
			Union(id, f_id, F);
		}
		if(m_id != -1){
			F[m_id].visited = true;
			Union(id, m_id, F);
		}

		for(int j=0; j<k; j++)
			Union(id, child[j], F);

		int f = Find(id, F);
		F[f].sites += sites;
		F[f].area += area;
	}

	set<Rank, Rule> result;
	for(int i=0; i<10000; i++){
		if(F[i].visited && F[i].parent<0){
			Rank r;
			r.id = i;
			r.F = F[i];
			result.insert(r);
		}
	}

	cout << result.size() << endl;
	for(auto iter = result.begin(); iter!=result.end(); ++iter){
		printf("%04d %d %.3f %.3f\n", iter->id, -iter->F.parent,
			iter->F.sites/(-1.0*iter->F.parent),
			iter->F.area/(-1.0*iter->F.parent));
	}

	return 0;
}
