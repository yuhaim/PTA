#include <iostream>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1118.txt", "r", stdin);
#endif

	int N;
	cin >> N;

	map<int, int> m;
	int id = 0;
	for(int i=0; i<N; i++){
		int K;
		cin >> K;

		vector<int> tree(K);
		int root = -1;
		for(int j=0; j<K; j++){
			cin >> tree[j];
			if(m.find(tree[j])!=m.end())
				root = m[tree[j]];
		}

		if(root==-1) 
			root = id++;

		for(int j=0; j<K; j++){
			m[tree[j]] = root;
		}
	}

	cout << id << ' ' << m.size() << endl;

	int Q;
	cin >> Q;
	for(int i=0; i<Q; i++){
		int p, q;
		cin >> p >> q;
		if(m[p]==m[q])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}