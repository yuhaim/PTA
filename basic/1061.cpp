#include<iostream>
#include<vector>

using namespace std;

struct Problem {
	int score;
	int answer;
};

int main()
{
	int N, M;
	cin >> N >> M;

	vector<Problem> book(M);
	for (int i = 0; i < M; i++) {
		cin >> book[i].score;
	}

	for (int i = 0; i < M; i++) {
		cin >> book[i].answer;
	}

	vector<int> score(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int ans;
			cin >> ans;
			if (ans == book[j].answer)
				score[i] += book[j].score;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << score[i] << endl;
	}

	return 0;
}