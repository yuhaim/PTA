#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Problem {
	int score;
	int n;
	int c;
	map<char, int> answer;
	map<char, int> wrong;
};

struct Wrong {
	int id;
	char ans;
	int count;
};

bool compare(Wrong x, Wrong y)
{
	if (x.count != y.count)
		return x.count > y.count;
	else if (x.id != y.id)
		return x.id < y.id;
	else
		return x.ans < x.ans;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<Problem> book(M);
	for (int i = 0; i < M; i++) {
		cin >> book[i].score
			>> book[i].n
			>> book[i].c;
		for (int j = 0; j < book[i].c; j++) {
			char temp;
			cin >> temp;
			book[i].answer[temp] = 0;
		}
	}

	getchar();

	for (int i = 0; i < N; i++) {
		double score = 0.0;
		bool init = true;

		for (int j = 0; j < M; j++) {
			if (init) {
				getchar();
				init = false;
			}
			else {
				getchar(); getchar(); getchar();
			}

			int count = 0;
			int n;
			cin >> n;

			while (n--) {
				char temp;
				cin >> temp;
				if (book[j].answer.find(temp) != book[j].answer.end()) {
					book[j].answer[temp]++;
					if(count >=0)
						count++;
				}
				else {
					book[j].wrong[temp]++;
					count = -1;
				}
			}

			for (map<char, int>::iterator iter = book[j].answer.begin();
				iter != book[j].answer.end(); iter++) {
				if (iter->second == 0) {
					book[j].wrong[iter->first]++;
				}
				else {
					iter->second = 0;
				}
			}

			if (count==-1) {
				;
			}
			else if (count == book[j].c) {
				score += book[j].score;
			}
			else {
				score += 0.5*book[j].score;
			}
		}
		getchar(); getchar();
		printf("%.1f\n", score);
	}

	vector<Wrong> record;
	for (int i = 0; i < M; i++) {
		for (map<char, int>::iterator iter = book[i].wrong.begin();
			iter != book[i].wrong.end(); iter++) {
			Wrong w;
			w.id = i + 1;
			w.ans = iter->first;
			w.count = iter->second;
			record.push_back(w);
		}
	}

	if (record.size() == 0)
		cout << "Too simple" << endl;
	else {
		sort(record.begin(), record.end(), compare);
		for (vector<Wrong>::iterator iter = record.begin();
			iter->count == record[0].count; iter++) {
			cout << iter->count << ' ' << iter->id << '-' << iter->ans << endl;
		}
	}

	return 0;
}