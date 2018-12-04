#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
vector<int> book(100001, -1);

int main()
{
	int N;
	cin >> N;

	while (N--) {
		int idx, idy;
		cin >> idx >> idy;
		book[idx] = idy;
		book[idy] = idx;
	}

	int M;
	cin >> M;

	vector<int> present(M);
	vector<int> alone(M, 1);
	for (int i = 0; i < M; i++) {
		int id;
		cin >> id;
		present[i] = id;
	}

	sort(present.begin(), present.end());
	int count = M;
	for (int i = 0; i < M; i++) {
		if (book[present[i]] != -1) {
			bool found = binary_search(present.begin(), present.end(), book[present[i]]);
			if (found){
				count--;
				alone[i] = 0;
			}	
		}
	}

	cout << count << endl;
	bool init = true;
	for (int i = 0; i < M;i++) {
		if (alone[i]) {
			if (init)
				init = false;
			else
				cout << ' ';
			printf("%05d", present[i]);
		}
	}

	return 0;
}