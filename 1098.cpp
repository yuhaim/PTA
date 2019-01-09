#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

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
		j=N-1;
		while(partial[j]>=partial[0])
			j--;
		int size_heap = j+1;
		vector<int> max_heap(size_heap+1);

		for(int k=0; k<=j; k++)
			max_heap[k+1] = partial[k];

		swap(max_heap[1], max_heap[size_heap--]);
		int value = max_heap[1];
		int parent = 1;
		while(2*parent<=size_heap){
			int child = 2*parent;
			if(child+1<=size_heap && max_heap[child+1] > max_heap[child])
				child++;
			if(value<max_heap[child]){
				max_heap[parent] = max_heap[child];
				parent = child;
			}else{
				break;
			}
		}
		max_heap[parent] = value;

		bool init = true;
		for(int k=0; k<=j; k++){
			if(init)
				init = false;
			else
				cout << ' ';
			cout << max_heap[k+1];
		}
		for(int k=j+1; k<N; k++){
			cout << ' ';
			cout << partial[k];
		}
	}
	
	return 0;
}