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
	}else{
		cout << "Heap Sort" << endl;
		j=N-1;
		while(partial[j]>=partial[0])
			j--;

		pop_heap(partial.begin(), partial.begin()+j+1);
	}

	bool init = true;
	for(int k=0; k<N; k++){
		if(init)
			init = false;
		else
			cout << ' ';
		cout << partial[k];
	}
	
	return 0;
}