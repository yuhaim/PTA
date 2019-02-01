#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int N;
vector<int> pre;
vector<int> post;
vector<int> in;
bool unique = true;

void dfs(int pre_left, int post_right, int length)
{
	if(length<=0)
		return;

	int p1_l=pre_left+1, p2_r=post_right-1;
	int p2_l=-1, p1_r=-1, length1, length2;
	for(int i=0; i<N; i++){
		if(p2_r >=0 && p2_r <= N-1 && pre[i]==post[p2_r]){
			p2_l = i;
		}
		if(p1_l >=0 && p1_l <= N-1 && post[i]==pre[p1_l]){
			p1_r = i;
		}
	}

	length1 = p2_l - p1_l;
	length2 = p2_r - p1_r;

	dfs(p1_l, p1_r, length1);
	in.push_back(pre[pre_left]);
	dfs(p2_l, p2_r, length2);

	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1119.txt", "r", stdin);
#endif

	cin >> N;
	pre.resize(N);
	post.resize(N);

	for(int i=0; i<N; i++){
		cin >> pre[i];
	}
	for(int i=0; i<N; i++){
		cin >> post[i];
	}

	dfs(0, N-1, N);

	if(unique){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << in[0];
	for(int i=1; i<N; i++){
		cout << ' ' << in[i];
	}

	return 0;
}