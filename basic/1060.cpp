#include <iostream>
#include <algorithm>

using namespace std;
int record[100005];
int main()
{
	int N;
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> record[i];
	}

	sort(record, record+N);

	int E = N;
	while(E>=0){
		int *index = upper_bound(record, record+N, E);
		if(N-(index - record)>=E)
			break;
		E--;
	}

	cout << E << endl;

	return 0;
}