#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
struct Family{
	set<int> ids;
	int members;
	int sites;
	int area;
};

struct Rule{
	bool operator()(const Family &x, const Family &y){
		if(fabs((double)x.area/x.members - (double)y.area/y.members)<1e-3)
			return *x.ids.begin() < *y.ids.begin();
		else
			return (double)x.area/x.members > (double)y.area/y.members;
	}
};

void insert_inc(Family &f, int member)
{
	auto result = f.ids.insert(member);
	if(result.second){
		f.members++;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1114.txt", "r", stdin);
#endif

	int N;
	cin >> N;

	vector<Family> v;
	for(int i=0; i<N; i++){
		vector<int> id(3);
		cin >> id[0] >> id[1] >> id[2];
		int k;
		cin >> k;
		vector<int> child(k);
		for(int j=0; j<k; j++){
			cin >> child[j];
		}
		int m_estate;
		int area;
		cin >> m_estate >> area;

		bool found = false;
		for(vector<Family>::iterator iter = v.begin(); !found && iter!=v.end(); ++iter){
			for(set<int>::iterator it = iter->ids.begin(); 
				!found && it!=iter->ids.end(); ++it){
				if(*it==id[0] || *it==id[1] || *it==id[2]){
					found = true;
					if(id[0]!=-1)
						insert_inc(*iter, id[0]);
					if(id[1]!=-1)
						insert_inc(*iter, id[1]);
					if(id[2]!=-1)
						insert_inc(*iter, id[2]);
					for(int j=0; j<k; j++){
						insert_inc(*iter, child[j]);
					}

					iter->sites += m_estate;
					iter->area += area;
				}
			}
		}

		if(!found){
			Family f;
			f.members = f.sites = f.area= 0;
			if(id[0]!=-1)
				insert_inc(f, id[0]);
			if(id[1]!=-1)
				insert_inc(f, id[1]);
			if(id[2]!=-1)
				insert_inc(f, id[2]);
			for(int j=0; j<k; j++){
				insert_inc(f, child[j]);
			}

			f.sites += m_estate;
			f.area += area;
			v.push_back(f);
		}
	}

	sort(v.begin(), v.end(), Rule());

	cout << v.size() << endl;
	for(vector<Family>::iterator iter = v.begin(); 
		iter!=v.end(); ++iter){
		printf("%04d %d %.3f %.3f\n",
				*(iter->ids.begin()), 
				iter->members,
				(double)iter->sites/iter->members,
				(double)iter->area/iter->members);
	}

	return 0;
}
