#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct Score{
	int G_p;
	int G_mid;
	int G_final;
};

struct Student{
	string id;
	Score s;
	int G;
};

int valid_score(Score s)
{
	if(s.G_p < 200)
		return -1;
	int G_mid = s.G_mid==-1 ? 0 : s.G_mid;
	int G_final = s.G_final==-1 ? 0 : s.G_final;
	double G;
	if(G_mid > G_final){
		G = 0.4*G_mid + 0.6*G_final;
	}else{
		G = 1.0*G_final;
	}

	if(G>=60)
		return (int)(G+0.5);
	else
		return -1;
}

bool compare(Student &x, Student &y)
{
	if(x.G!=y.G){
		return x.G > y.G;
	}else{
		return x.id < y.id;
	}
}

int main()
{
	int P, M, N;
	cin >> P >> M >> N;

	map<string, Score> map_data;

	for(int i=0; i<P; i++){
		string id;
		int score;
		cin >> id >> score;
		
		if(map_data.find(id)!=map_data.end()){
			map_data[id].G_p = score;
		}else{
			Score s;
			s.G_p = score;
			s.G_mid = -1;
			s.G_final = -1;
			map_data[id] = s;
		}
	}

	for(int i=0; i<M; i++){
		string id;
		int score;
		cin >> id >> score;
		
		if(map_data.find(id)!=map_data.end()){
			map_data[id].G_mid = score;
		}else{
			Score s;
			s.G_p = -1;
			s.G_mid = score;
			s.G_final = -1;
			map_data[id] = s;
		}
	}

	for(int i=0; i<N; i++){
		string id;
		int score;
		cin >> id >> score;
		
		if(map_data.find(id)!=map_data.end()){
			map_data[id].G_final = score;
		}else{
			Score s;
			s.G_p = -1;
			s.G_mid = -1;
			s.G_final = score;
			map_data[id] = s;
		}
	}

	vector<Student> total_list;
	for(map<string, Score>::iterator iter = map_data.begin();
		iter != map_data.end(); iter++){
		int G = valid_score(iter->second);
		if(G!=-1){
			Student st;
			st.id = iter->first;
			st.s = iter->second;
			st.G = G;
			total_list.push_back(st);
		}
	}

	sort(total_list.begin(), total_list.end(), compare);

	for(int i=0; i<total_list.size(); i++){
		cout << total_list[i].id << ' '
			<< total_list[i].s.G_p << ' '
			<< total_list[i].s.G_mid << ' '
			<< total_list[i].s.G_final << ' '
			<< total_list[i].G << endl;
	}

	return 0;
}