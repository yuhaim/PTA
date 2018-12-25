#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Person{
	string id;
	char c;
	int room;
	int day;
	int ser;
	int score;
};

struct Room{
	int room;
	int count;
};

bool compare_c(Person &x, Person &y)
{
	return x.score!=y.score ? x.score>y.score : x.id<y.id;
}

bool compare_room(Room &x, Room &y)
{
	return x.count!=y.count ? x.count>y.count : x.room<y.room;
}

int main()
{
	int M, N;
	cin >> N >> M;

	vector<Person> record(N);
	for(int i=0; i<N; i++){
		string id;
		int score;
		cin >> id >> score;

		char c = id[0];
		int room = stoi(id.substr(1, 3));
		int day = stoi(id.substr(4, 6));
		int ser = stoi(id.substr(10));

		Person p;
		p.id = id;
		p.c = c;
		p.room = room;
		p.day = day;
		p.ser = ser;
		p.score = score;
		record[i] = p;
	}

	for(int i=0; i<M; i++){
		int cmd_type;
		cin >> cmd_type;

		int num_person = 0;
		int sum_score = 0;

		int j;
		vector<Person> query;
		unordered_map<int, int> room_map;
		vector<Room> room_count;
		switch(cmd_type){
		case 1:
			char c;
			cin >> c;
			cout << "Case " << i+1 << ": " << "1 " << c << endl; 
			for(j=0; j<N; j++){
				if(record[j].c == c)
					query.push_back(record[j]);
			}

			if(query.size()==0){
				cout << "NA" << endl;
				break;
			}

			sort(query.begin(), query.end(), compare_c);

			for(j=0; j<query.size(); j++){
				printf("%s %d\n", query[j].id.c_str(), query[j].score);
			}
			
			break;
		case 2:
			int room;
			cin >> room;
			cout << "Case " << i+1 << ": " << "2 " << room << endl; 
			
			for(j=0; j<N; j++){
				if(record[j].room == room){
					num_person++;
					sum_score += record[j].score;
				}
			}

			if(num_person==0){
				cout << "NA" << endl;
				break;
			}
			
			cout << num_person << ' ' << sum_score << endl;
			break;
		case 3:
			int day;
			cin >> day;
			cout << "Case " << i+1 << ": " << "3 " << day << endl; 
			for(j=0; j<N; j++){
				if(record[j].day == day)
					room_map[record[j].room]++;
			}

			for(auto iter = room_map.begin();
				iter!=room_map.end();iter++){
				Room r;
				r.room = iter->first;
				r.count = iter->second;
				room_count.push_back(r);
			}

			if(room_count.size()==0){
				cout << "NA" << endl;
				break;
			}

			sort(room_count.begin(), room_count.end(), compare_room);

			for(j=0; j<room_count.size(); j++){
				printf("%d %d\n", room_count[j].room, room_count[j].count);
			}

			break;
		}
	}
	
	return 0;
}
