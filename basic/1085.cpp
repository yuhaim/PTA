#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Score{
	int b_sum;
	int a_sum;
	int t_sum;
	int count;
};

struct School{
	string name;
	int score;
	int count;
};

bool compare(School x, School y)
{
	if(x.score!=y.score)
		return x.score > y.score;
	else if(x.count!=y.count)
		return x.count < y.count;
	else
		return x.name < y.name;
}

int main()
{
	int N; 
	cin >> N;

	map<string, Score> record;
	while(N--){
		string school;
		string id;
		int score;
		cin >> id >> score >> school;

		for(int i=0; i<school.length(); i++)
			school[i] = tolower(school[i]);

		if(record.find(school)==record.end()){
			Score s = {0 ,0 ,0 ,0};
			record[school] = s;
		}
		switch(id[0]){
		case 'B':
			record[school].b_sum += score;
			record[school].count++;
			break;
		case 'A':
			record[school].a_sum += score;
			record[school].count++;
			break;
		case 'T':
			record[school].t_sum += score;
			record[school].count++;
			break;
		}
	}

	vector<School> order_list;
	for(map<string, Score>::iterator iter = record.begin();
		iter!=record.end(); iter++){
		School s;
		s.name = iter->first;
		s.count = iter->second.count;
		s.score = iter->second.b_sum/1.5 + 
					iter->second.a_sum + 
					iter->second.t_sum*1.5;
		order_list.push_back(s);
	}

	sort(order_list.begin(), order_list.end(), compare);

	cout << order_list.size() << endl;
	int k = 1;
	cout << k << ' ' 
		<< order_list[0].name << ' '
		<< order_list[0].score << ' '
		<< order_list[0].count << endl;
	for(int i=1; i<order_list.size(); i++){
		if(order_list[i].score < order_list[i-1].score)
			k=i+1;
		cout << k << ' ' 
		<< order_list[i].name << ' '
		<< order_list[i].score << ' '
		<< order_list[i].count << endl;
	}

	return 0;
}
