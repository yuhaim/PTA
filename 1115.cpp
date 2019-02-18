#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Node{
	int value;
	int left;
	int right;
	int level;
};

int N;
vector<Node> tree;
int next_index;
int max_level;
int n1, n2;

int insert_node(int root, int value, int level)
{
	if(root == -1){
		next_index++;
		tree[next_index].value = value;
		tree[next_index].left = -1;
		tree[next_index].right = -1;
		tree[next_index].level = level;
		if(level > max_level)
			max_level = level;
		return next_index;
	}

	if(value<=tree[root].value)
		tree[root].left = insert_node(tree[root].left, value, level+1);
	else
		tree[root].right = insert_node(tree[root].right, value, level+1);

	return root;
}

void pre_order(int root)
{
	if(root==-1)
		return;
	if(tree[root].level == max_level)
		n1++;
	else if(tree[root].level == max_level - 1)
		n2++;
	pre_order(tree[root].left);
	pre_order(tree[root].right);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1115.txt", "r", stdin);
#endif

	cin >> N;
	tree.resize(N);

	cin >> tree[0].value;
	tree[0].left = -1;
	tree[0].right = -1;
	tree[0].level = 1;

	for(int i=1; i<N; i++){
		int temp;
		cin >> temp;
		insert_node(0, temp, 1);
	}

	pre_order(0);

	cout << n1 << " + " << n2 << " = " << n1+n2;
	return 0;
}