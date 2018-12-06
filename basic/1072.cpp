#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	set<int> book;

	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		book.insert(temp);
	}

	int n = 0, m = 0;

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;

		int K;
		cin >> K;
		bool init = true;
		int count = 0;
		for (int j = 0; j < K; j++) {
			int temp;
			cin >> temp;

			if (book.find(temp) != book.end()) {
				if (init) {
					cout << name << ": ";
					init = false;
				}
				else
					cout << ' ';
				printf("%04d", temp);
				count++;
			}

		}

		if (count) {
			n++;
			m += count;
			cout << endl;
		}
	}

	cout << n << ' ' << m << endl;

	return 0;
}