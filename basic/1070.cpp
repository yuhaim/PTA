#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> data(N);
	for (int i = 0; i < N; i++) {
		cin >> data[i];
	}

	sort(data.begin(), data.end());

	double sum = data[0];
	for (int i = 1; i < N; i++) {
		sum = 0.5*(sum + data[i]);
	}

	cout << (int)sum << endl;
	return 0;
}