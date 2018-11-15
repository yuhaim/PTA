#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int A = 0, B = 0;

	while(N--){
		int A_a, A_b, B_a, B_b;
		cin >> A_a >> A_b >> B_a >> B_b;
		if(A_b == A_a + B_a && B_b != A_a + B_a)
			B++;
		else if(A_b != A_a + B_a && B_b == A_a + B_a)
			A++;
		else{
		}
	}

	cout << A << ' ' << B << endl;
	return 0;
}