#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	cin >> N;
	double max_r = 0.0;

	while (N--) {
		int a, b;
		cin >> a >> b;
		double r = sqrt(a*a + b * b);
		if (max_r < r)
			max_r = r;
	}

	printf("%.2f\n", max_r);
	return 0;
}