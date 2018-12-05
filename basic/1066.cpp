#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int M, N;
	int A, B, E;

	cin >> M >> N >> A >> B >> E;

	for (int i = 0; i < M; i++) {
		bool init = true;
		for (int j = 0; j < N; j++) {
			if (init) init = false; 
			else printf(" ");
			int C;
			scanf("%d", &C);

			if (C >= A && C <= B)
				printf("%03d", E);
			else
				printf("%03d", C);
		}
		printf("\n");
	}

	return 0;
}