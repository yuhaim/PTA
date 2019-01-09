#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> max_heap;
int size_heap;

void insert_heap(int val)
{
	int sz = ++size_heap;
	while(val>max_heap[sz/2]){
		max_heap[sz]=max_heap[sz/2];
		sz /= 2;
	}
	max_heap[sz] = val;
}

void delete_heap()
{
	swap(max_heap[1], max_heap[size_heap--]);
	int val = max_heap[1];
	int i=1;
	while(2*i<=size_heap){
		int child = 2*i;
		if(child+1<=size_heap && max_heap[child+1] > max_heap[child])
			child++;
		if(val > max_heap[child])
			break;
		else{
			max_heap[i] = max_heap[child];
			i = child;
		}
	}
	max_heap[i] = val;
}

void build_heap(vector<int> &src)
{
	for(int i=0; i<src.size(); i++){
		insert_heap(src[i]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1098.txt", "r", stdin);
#endif
	int N;
	cin >> N;

	vector<int> src(N);
	for(int i=0; i<N; i++){
		cin >> src[i];
	}

	vector<int> partial(N);
	for(int i=0; i<N; i++){
		cin >> partial[i];
	}

	int i=1, j;
	while(i<N && partial[i]>=partial[i-1])
		i++;
	j=i;
	while(i<N && partial[i]==src[i])
		i++;
	if(i==N){
		cout << "Insertion Sort" << endl;
		sort(partial.begin(), partial.begin()+j+1);
		bool init = true;
		for(int k=0; k<N; k++){
			if(init)
				init = false;
			else
				cout << ' ';
			cout << partial[k];
		}
	}else{
		cout << "Heap Sort" << endl;
		max_heap.resize(N+1);
		max_heap[0] = 999999999;
		size_heap = 0;

		build_heap(src);
		j=N-1;
		while(j>=0){
			delete_heap();
			int k;
			for(k=0; k<N; k++)
				if(max_heap[k+1] != partial[k]) 
					break;
			if(k==N){
				delete_heap();
				bool init = true;
				for(int m=0; m<N; m++){
					if(init)
						init = false;
					else
						cout << ' ';
					cout << partial[m];
				}
			}
		}

	}
	
	return 0;
}