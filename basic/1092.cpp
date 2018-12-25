#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> data(N+1);

	while(M--){
		for(int i=1; i<=N; i++){
			int x;
			cin >> x;
			data[i] += x;
		}
	}

	int max_value = -1;
	for(int i=1; i<=N; i++){
		if(max_value < data[i])
			max_value = data[i];
	}

	cout << max_value << endl;

	bool init = true;
	for(int i=1; i<=N; i++){
		if(max_value == data[i]){
			if(init)
				init = false;
			else
				cout << ' ';
			cout << i;
		}
	}

	return 0;
}