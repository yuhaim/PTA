#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

bool is_max_heap(int root, const vector<int> &tree)
{
	if(root > tree.size()-1)
		return true;
	return tree[root]<=tree[root/2] &&
		is_max_heap(2*root, tree) && 
		is_max_heap(2*root+1, tree);
}

bool is_min_heap(int root, const vector<int> &tree)
{
	if(root > tree.size()-1)
		return true;
	return tree[root]>=tree[root/2] &&
		is_min_heap(2*root, tree) && 
		is_min_heap(2*root+1, tree);
}

int is_heap(vector<int> &tree)
{
	tree[0] = INT_MAX;
	if(is_max_heap(1, tree))
		return 1;
	tree[0] = INT_MIN;
	if(is_min_heap(1, tree))
		return -1;
	//if(is_heap(tree.begin()+1, tree.end())) return 1;
	//if(is_heap(tree.begin()+1, tree.end(), greater<int>())) return -1;
	return 0;
}

bool init;
void post_order(int root, int max_index, const vector<int> &tree)
{
	if(root>max_index)
		return;
	post_order(2*root, max_index, tree);
	post_order(2*root+1, max_index, tree);

	if(init) 
		init=false; 
	else 
		cout << ' ';
	cout << tree[root];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1147.txt", "r", stdin);
#endif

	int M, N;
	cin >> M >> N;
	for(int i=0; i<M; i++){
		vector<int> tree(N+1);
		for(int j=0; j<N; j++){
			cin >> tree[j+1];
		}

		switch(is_heap(tree)){
		case 1:
			cout << "Max Heap" << endl;
			break;
		case -1:
			cout << "Min Heap" << endl;
			break;
		case 0:
			cout << "Not Heap" << endl;
			break;
		}
		init = true;
		post_order(1, N, tree);
		cout << endl;
	}

	return 0;
}