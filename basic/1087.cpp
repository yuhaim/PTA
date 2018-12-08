#include <iostream>

using namespace std;
int mem_space[12000];
int main()
{
	int N;
	cin >> N;

	for(int i=N; i>=1; i--){
		mem_space[i/5 + i/3 + i/2] = 1;
	}

	int count  = 0;
	for(int i=0; i<=N/5 + N/3 + N/2; i++){
		if(mem_space[i])
			count++;
	}

	cout << count << endl;

	return 0;
}