#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
struct Node {
	int left;
	int right;
	int num_node;
	int value;
};

vector<Node> tree;

void post_order_count(int root)
{
	if (root == -1) return;

	post_order_count(tree[root].left);
	post_order_count(tree[root].right);
	if (tree[root].left != -1)
		tree[root].num_node += tree[tree[root].left].num_node;
	if (tree[root].right != -1)
		tree[root].num_node += tree[tree[root].right].num_node;
}

void pre_order_fill(int root, int low, const vector<int> &seq)
{
	if (root == -1)
		return;

	int index;
	if (tree[root].left != -1)
		index = low + tree[tree[root].left].num_node;
	else
		index = low;

	tree[root].value = seq[index];

	pre_order_fill(tree[root].left, low, seq);
	pre_order_fill(tree[root].right, index+1, seq);
}

bool init = true;
void level_order(int root)
{
	queue<int> que;
	que.push(root);
	while (!que.empty()) {
		int curr = que.front();
		if (init)
			init = false;
		else
			cout << ' ';

		cout << tree[curr].value;
		que.pop();
		if (tree[curr].left != -1)
			que.push(tree[curr].left);
		if (tree[curr].right != -1)
			que.push(tree[curr].right);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("..\\..\\PTA\\1099.txt", "r", stdin);
#endif

	int N;
	cin >> N;
	tree.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> tree[i].left >> tree[i].right;
		tree[i].num_node = 1;
	}

	vector<int> seq(N);
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}
	sort(seq.begin(), seq.end());

	post_order_count(0);
	pre_order_fill(0, 0, seq);
	level_order(0);

	return 0;
}