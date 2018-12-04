#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int N, int M)
{
	if (N == 0)
		return M;
	else
		return gcd(M%N, N);
}

int main()
{
	int N1, M1, N2, M2, K;
	scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);

	int EN1 = N1*M2*K;
	int EN2 = N2*M1*K;

	bool init = true;
	for (int i = 1; i < 1001; i++) {
		int EN = i * M1* M2;
		if (EN > EN1 && EN < EN2 && gcd(i, K) == 1) {
			if (init)
				init = false;
			else
				cout << ' ';
			cout << i << '/' << K;
		}
	}
	
	cout << endl;

	return 0;
}
