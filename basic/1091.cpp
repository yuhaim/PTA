#include <iostream>

using namespace std;

int check(int K)
{
	int temp = K;
	int base = 1;

	while(temp){
		base *= 10;
		temp /= 10;
	}

	int N;
	for(N=1; N < 10; N++){
		if(N*K*K%base == K)
			break;
	}

	return N;
}

int main()
{
	int M;
	cin >> M;

	while(M--){
		int K;
		cin >> K;

		int N = check(K);
		if(N==10){
			cout << "No" << endl;
		}else{
			cout << N << ' ' << N*K*K << endl;
		}
	}

	return 0;
}