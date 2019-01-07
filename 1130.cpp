#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

struct Node{
	string s;
	int left;
	int right;
	int parent;
};

int in_order(int root)
{
	if(root = -1)
		return root;



	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1130.txt", "r", stdin);
#endif

	int N;
	cin >> N;
	vector<Node> tree(N+1);

	for(int i=1; i<=N; i++){
		cin >> tree[i].s >> tree[i].left >> tree[i].right;
		if(tree[i].left!=-1)
			tree[tree[i].left].parent = i;
		if(tree[i].right!=-1)
			tree[tree[i].right].parent = i;
	}

	int root;
	for(int i=1; i<=N; i++){
		if(tree[i].parent==0){
			root = i;
		}
	}

	in_order(root);

	return 0;
}