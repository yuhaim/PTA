#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
	int data;
	int next;
};

struct List {
	int addr;
	int data;
};

Node mem_space[100001];

int main()
{
	int start_addr, N, K;
	cin >> start_addr >> N >> K;

	for (int i = 0; i < N; i++) {
		int addr, data, next;
		cin >> addr >> data >> next;
		mem_space[addr].data = data;
		mem_space[addr].next = next;
	}

	vector<List> negative;
	vector<List> in_range;
	vector<List> others;

	int p = start_addr;
	while (p != -1) {
		List L;
		L.addr = p;
		L.data = mem_space[p].data;
		if (L.data < 0) {
			negative.push_back(L);
		}
		else if (L.data >= 0 && L.data <= K) {
			in_range.push_back(L);
		}
		else {
			others.push_back(L);
		}

		p = mem_space[p].next;
	}

	bool init = true;
	for (int i = 0; i < negative.size(); i++) {
		if (init)
			init = false;
		else
			printf("%05d\n", negative[i].addr);

		printf("%05d %d ", negative[i].addr, negative[i].data);
	}

	for (int i = 0; i < in_range.size(); i++) {
		if (init)
			init = false;
		else
			printf("%05d\n", in_range[i].addr);

		printf("%05d %d ", in_range[i].addr, in_range[i].data);
	}

	for (int i = 0; i < others.size(); i++) {
		if (init)
			init = false;
		else
			printf("%05d\n", others[i].addr);

		printf("%05d %d ", others[i].addr, others[i].data);
	}

	cout << -1 << endl;
	return 0;
}