#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

struct Node {
	int parent;
	int left;
	int right;
};

int max_index;
int max_node;
void dfs(int root, int index, const vector<Node> &tree)
{
	if(root == -1)
		return;
	if(index > max_index){
		max_index = index;
		max_node = root;
	}
	dfs(tree[root].left, 2*index, tree);
	dfs(tree[root].right, 2*index+1, tree);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1110.txt", "r", stdin);
#endif

	int N;
	cin >> N;

	int root = -1;
	Node init_node = {-1, -1, -1};
	vector<Node> tree(N, init_node);
	for (int i = 0; i < N; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		tree[i].left = s1[0] == '-' ? -1 : stoi(s1);
		if (tree[i].left != -1)
			tree[tree[i].left].parent = i;
		tree[i].right = s2[0] == '-' ? -1 : stoi(s2);
		if (tree[i].right != -1)
			tree[tree[i].right].parent = i;
	}

	for (int i = 0; i < N; i++) {
		if (tree[i].parent == -1) {
			root = i;
			break;
		}
	}

	dfs(root, 1, tree);
	if(max_index == N)
		cout << "YES " << max_node << endl;
	else
		cout << "NO " << root << endl;

	return 0;
}