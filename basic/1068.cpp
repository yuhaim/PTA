#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int color_map[1001][1001];

int min_tol(int n, int m)
{
	int min_value = INT_MAX;
	for(int i=-1;i<=1;i++)
		for (int j = -1; j <= 1; j++) {
			int value = abs(color_map[n][m] - color_map[n + i][m + j]);
			if (!(i==0 && j==0) && min_value > value)
				min_value = value;
		}
	return min_value;
}

int main()
{
	int M, N, TOL;
	cin >> M >> N >> TOL;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &color_map[i][j]);
		}
	}

	int x = 0, y = 0, tol = 0, color_value = 0;
	bool is_unique = true;
	for (int i = 2; i <= N-1; i++) {
		for (int j = 2; j <= M-1; j++) {
			int tol_value = min_tol(i, j);
			if (tol_value <= TOL)
				continue;
			else if (tol_value > tol) {
				y = i;
				x = j;
				color_value = color_map[i][j];
				tol = tol_value;
				is_unique = true;
			}
			else if (tol_value == tol) {
				is_unique = false;
			}else{}
		}
	}

	if (tol == 0)
		cout << "Not Exist" << endl;
	else if (!is_unique)
		cout << "Not Unique" << endl;
	else {
		cout << "(" << x << ", " << y << "):" << color_value;
	}

	return 0;
}