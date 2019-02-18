#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

vector<int> in;
vector<int> post;
map<int, vector<int>> levels;

void dfs(int post_left, int post_right, int in_left,
		int level)
{
	if(post_left>post_right)
		return;

	int root_value = post[post_right];
	levels[level].push_back(root_value);

	int tree_length = post_right - post_left + 1;
	int index;
	for(index=in_left; index<in_left+tree_length; index++){
		if(in[index]==root_value) break;
	}

	int left_length = index - in_left;
	int right_length = tree_length - left_length - 1;
	dfs(post_left, post_left+left_length-1, in_left, level+1);
	dfs(post_left+left_length, post_right-1, index+1, level+1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1127.txt", "r", stdin);
#endif

	int N;
	cin >> N;

	in.resize(N);
	post.resize(N);

	for(int i=0; i<N; i++){
		cin >> in[i];
	}
	for(int i=0; i<N; i++){
		cin >> post[i];
	}

	dfs(0, N-1, 0, 1);

	cout << levels[1][0];
	for(int i=2; i<=levels.size(); i++){
		if(i%2){
			for(int j=levels[i].size()-1; j>=0; j--){
				cout << ' ' << levels[i][j];
			}

		}else{
			for(int j=0; j<levels[i].size(); j++){
				cout << ' ' << levels[i][j];
			}
		}
	}

	return 0;
}