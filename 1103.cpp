#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N, K, P;
int n_pow(int n, int K)
{
	int prod = 1;
	while(K>0){
		prod *= n;
		K--;
	}
}

bool flag = false;
void dfs(vector<int> &n, int curr, int sum)
{
	int rem = N - sum - (K - 1 - curr);
	if(rem<1)
		return;

	int guass = sqrt(1.0*rem) ;
	n[curr] = guass;

	int sum = 0;
	for(int i=0; i<K; i++){
		sum += n_pow(n[i], P);
	}

	if(sum == N){
		flag = true;
		return;
	} else if(sum>N && guass>1){
		guass--;

	}
}

int main()
{
	cin >> N >> K >> P;

	vector<int> n(K, 1);

	if(!flag){
		cout << "Impossible";
		return 0;
	}

	cout << N << " = " << n[0] << '^' << P;
	for(int i=1; i<K; i++){
		cout << " + " << n[i] << '^' << P;
	}
	return 0;
}