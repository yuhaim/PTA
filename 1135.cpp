#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Node{
	int value;
	struct Node *left, *right;
};

struct Info{
	int height;
	int color;
};

bool status;

struct Node *build_tree(int start, int length, const vector<int> &pre_order)
{
	if(length <= 0 || start <0 || start >= pre_order.size())
		return nullptr;

	struct Node *root = new Node;
	root->value = pre_order[start];

	int split;
	for(split = start+1; split<start+length; split++){
		if(abs(pre_order[split])>abs(root->value))
			break;
	}

	root->left = build_tree(start+1, split-(start+1), pre_order);
	root->right = build_tree(split, start+length-split, pre_order);

	return root;
}

Info dfs(const struct Node *root)
{
	Info info;
	info.height = 1;
	info.color = 1;
	if(root==nullptr || status==false)
		return info;

	Info left = dfs(root->left);
	Info right = dfs(root->right);

	if(root->value<0 && (left.color<0 || right.color<0)){
		status = false;
		return info;
	}

	if(left.height != right.height){
		status = false;
		return info;
	}

	if(root->value > 0){
		info.color = 1;
		info.height = left.height + 1;
	} else { 
		info.color = -1;
		info.height = left.height;
	}

	return info;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1135.txt", "r", stdin);
#endif

	int K;
	cin >> K;

	for(int i=0; i<K; i++){
		int N;
		cin >> N;

		vector<int> pre_order(N);
		for(int j=0; j<N; j++)
			cin >> pre_order[j];

		if(pre_order[0]<0) {
			cout << "No" << endl;
			continue;
		}

		struct Node *root = build_tree(0, pre_order.size(), pre_order);
		status = true;
		dfs(root);
		if(status){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
