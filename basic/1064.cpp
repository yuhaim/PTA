#include <iostream>

using namespace std;
int id_data[10005];

int get_id(int x)
{
	int id = 0;
	while (x) {
		id += x % 10;
		x /= 10;
	}

	return id;
}

int main()
{
	int N;
	cin >> N;

	int count = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		int id = get_id(x);
		if (!id_data[id]) {
			count++;
			id_data[id] = 1;
		}
	}

	cout << count << endl;

	bool init = true;
	for (int i = 0; i < 10005; i++) {
		if (id_data[i]) {
			if (init)
				init = false;
			else
				cout << ' ';
			cout << i;
		}
	}

	cout << endl;

	return 0;
}