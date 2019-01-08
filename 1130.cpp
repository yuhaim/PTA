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

string out_str;

void in_order(int root, vector<Node> &tree)
{
	int child;
	child = tree[root].left;
	if(child!=-1){
		bool has_child = tree[child].left!=-1 || tree[child].right!=-1;
		if(has_child) out_str += '(';
		in_order(child, tree);
		if(has_child) out_str += ')';
	}

	out_str += tree[root].s;

	child = tree[root].right;
	if(child!=-1){
		bool has_child = tree[child].left!=-1 || tree[child].right!=-1;
		if(has_child) out_str += '(';
		in_order(child, tree);
		if(has_child) out_str += ')';
	}

	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1130.txt", "r", stdin);
#endif

	int N;
	cin >> N;
	Node init_node = {"", 0, 0, 0};
	vector<Node> tree(N+1, init_node);

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

	in_order(root, tree);
	cout << out_str;

	return 0;
}