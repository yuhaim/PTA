#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
};

Node *insert(Node *root, int value)
{
	if(root==nullptr){
		root = new Node;
		root->value = value;
		root->left = nullptr;
		root->right = nullptr;
		return root;
	}

	if(value<root->value)
		root->left = insert(root->left, value);
	else
		root->right = insert(root->right, value);

	return root;
}

vector<int> trace;
void find_value(const Node *root, int value)
{
	if(root == nullptr){
		trace.clear();
		return;
	}
	if(root->value == value){
		trace.push_back(value);
		return;
	}else{
		trace.push_back(root->value);

		if(value<root->value)
			find_value(root->left, value);
		else
			find_value(root->right, value);
	}
}

vector<int> trace_path(const Node *root, int value)
{
	trace.clear();
	find_value(root, value);
	return trace;
}

int find_LCA(const vector<int> &pU, const vector<int> &pV)
{
	unordered_set<int> set_V;
	for(int i=0; i<pV.size(); i++)
		set_V.insert(pV[i]);

	for(int i=pU.size()-1; i>=0; i--){
		if(set_V.count(pU[i]))
			return pU[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1143.txt", "r", stdin);
#endif

	int M, N;
	cin >> M >> N;

	Node *tree = nullptr;
	for(int i=0; i<N; i++){
		int temp;
		scanf("%d", &temp);
		tree = insert(tree, temp);
	}

	for(int i=0; i<M; i++){
		int U, V;
		scanf("%d%d", &U, &V);
		vector<int> pU = trace_path(tree, U);
		vector<int> pV = trace_path(tree, V);

		if(pU.empty() && pV.empty()){
			printf("ERROR: %d and %d are not found.\n", U, V);
			continue;
		}

		if(pU.empty()){
			printf("ERROR: %d is not found.\n", U);
			continue;
		}

		if(pV.empty()){
			printf("ERROR: %d is not found.\n", V);
			continue;
		}

		int A = find_LCA(pU, pV);

		if(A==U){
			printf("%d is an ancestor of %d.\n", U, V);
		} else if(A==V){
			printf("%d is an ancestor of %d.\n", V, U);
		} else {
			printf("LCA of %d and %d is %d.\n", U, V, A);
		}
	}

	return 0;
}