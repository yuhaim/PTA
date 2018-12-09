#include <iostream>
#include <cmath>

using namespace std;

void compare(int x, double y)
{
	if(x>y)
		cout << " Gai";
	else if(x<y)
		cout << " Cong";
	else
		cout << " Ping";
}

int main()
{
	int M, X, Y;
	cin >> M >> X >> Y;
	int A, B;
	double C;
	
	for(A=99; A>9; A--){
		int P = A/10;
		int Q = A%10;
		B = 10*Q + P;

		if(fabs(abs(A-B)/(double)X - B/(double)Y)<1e-5){
			C = B/(double)Y;
			break;
		}
	}

	if(A==9){
		cout << "No Solution" << endl;
		return 0;
	}

	cout << A;
	compare(M, A);
	compare(M, B);
	compare(M, C);
	cout << endl;
	return 0;
}