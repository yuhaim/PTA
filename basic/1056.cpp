#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> digits(N);

	for(int i=0; i<N; i++){
		cin >> digits[i];	
	}

	int sum = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++){
			if(i==j) continue;
			else{
				sum += digits[i]*10+digits[j];
			}
		}

	cout << sum << endl;

	return 0;
}