#include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int mul = A*B;
	int sum = 0;
	while(mul){
		sum = 10*sum + mul%10;
		mul /= 10;
	}
	cout << sum << endl;
	return 0;
}