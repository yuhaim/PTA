#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Problem{
	int score;
	string answer;
	int count;
};

int main()
{
	int N, M;
	cin >> N >> M;
	vector<Problem> book(M);

	for(int i=0; i<M; i++){
		Problem p;
		cin >> p.score;

		int total, correct;
		cin >> total >> correct;
		for(int j=0; j<correct; j++){
			char c;
			cin >> c;
			p.answer += c;
		}
		p.count = 0;
		book[i] = p;
	}

	string buf;
	getline(cin, buf);

	for(int i=0; i<N; i++){
		int score = 0;
		string ans;
		getline(cin, ans);
		int index = 0;
		for(int j=0; j<M; j++){
			int num = ans[++index]-'0';

			string ans_p;
			for(int k=1; k<=num; k++){
				index += 2;
				ans_p += ans[index];
			}
			index+=3;

			if(ans_p == book[j].answer)
				score += book[j].score;
			else
				book[j].count++;
		}

		cout << score << endl;
	}

	int max_count = 0;
	for(int i=0; i<M; i++){
		if(max_count < book[i].count)
			max_count = book[i].count;
	}

	if(!max_count){
		cout << "Too simple" << endl;
	} else {
		cout << max_count;
		for(int i=0; i<M; i++){
			if(max_count == book[i].count)
				cout << ' ' << i+1;
		}
		cout << endl;
	}
	return 0;
}