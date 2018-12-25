#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int parent;
	int left;
	int right;
};

bool init = true;

void in_order(const vector<Node> &tree, int root) {
	if (tree[root].right != -1) {
		in_order(tree, tree[root].right);
	}

	if (init)
		init = false;
	else
		cout << ' ';

	cout << root;

	if (tree[root].left != -1) {
		in_order(tree, tree[root].left);
	}
}

int main()
{
	int N;
	cin >> N;

	vector<Node> tree(N, {-1,-1,-1});
	
	for (int i = 0; i < N; i++) {
		char left, right;
		cin >> left >> right;

		if (isdigit(left)) {
			tree[i].left = left - '0';
			tree[left - '0'].parent = i;
		}

		if (isdigit(right)) {
			tree[i].right = right - '0';
			tree[right - '0'].parent = i;
		}
	}

	int root = 0;
	while (tree[root].parent != -1) {
		root = tree[root].parent;
	}

	queue<int> Q;
	Q.push(root);
	while (!Q.empty()) {
		if (init)
			init = false;
		else
			cout << ' ';

		cout << Q.front();
		if (tree[Q.front()].right != -1) {
			Q.push(tree[Q.front()].right);
		}
		if (tree[Q.front()].left!=-1) {
			Q.push(tree[Q.front()].left);
		}

		Q.pop();
	}

	cout << endl;
	init = true;

	in_order(tree, root);

	return 0;
}