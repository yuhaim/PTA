#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

struct Node {
	int parent;
	int left;
	int right;
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("..\\..\\PTA\\1110.txt", "r", stdin);
#endif

	int N;
	cin >> N;

	int root = -1;
	vector<Node> tree(N, {-1,-1,-1});
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



	return 0;
}