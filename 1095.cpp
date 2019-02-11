#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct Record{
	string plate;
	int sec;
	int state;
};

struct Stat{
	int duration;
	string plate;
};

string sec2hms(int sec)
{
	char t[9] = {'\0'};
	int h, m, s;
	h = sec/3600;
	m = (sec%3600)/60;
	s = sec%60;
	sprintf(t, "%02d:%02d:%02d", h, m, s);
	return string(t);
}

int hms2sec(string t)
{
	return stoi(t.substr(0,2))*3600 + 
			stoi(t.substr(3,2))*60 + 
			stoi(t.substr(6,2));
}

bool cmp_valid(const Record &x, const Record &y)
{
	return x.plate == y.plate ? x.sec < y.sec : x.plate < y.plate;
}

bool cmp_time(const Record &x, const Record &y)
{
	return x.sec < y.sec;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1095.txt", "r", stdin);
#endif

	int N, K;
	cin >> N >> K;

	vector<Record> data(N);
	for(int i=0; i<0; i++){
		string plate, t, state;
		cin >> plate >> t >> state;

		Record r;
		r.plate = plate;
		r.sec = hms2sec(t);
		r.state = state == "in" ? 1 : -1;
		data[i] = r;
	}

	sort(data.begin(), data.end(), cmp_valid);

	vector<Record> valid_data;
	unordered_map<string, int> map_duration;
	int max_duration = 0;
	for(int i=0; i<N-1; i++){
		if(data[i].plate == data[i+1].plate && data[i].state==1 && data[i].state==-1){
			valid_data.push_back(data[i]);
			valid_data.push_back(data[i+1]);
			map_duration[data[i].plate] += data[i+1].sec - data[i].sec;

			if(max_duration < map_duration[data[i].plate])
				max_duration = map_duration[data[i].plate];
		}
	}

	sort(valid_data.begin(), valid_data.end(), cmp_time);
	vector<int> parked(valid_data.size());
	int count = 0;
	for(int i=0; i<valid_data.size(); i++){
		count += valid_data[i].state;
		parked[i] = count;
	}

	int last_index = 0;
	for(int i=0; i<K; i++){
		string t;
		cin >> t;
		int sec = hms2sec(t);

		int j=last_index;
		for(int k=j; k<valid_data.size(); k++){
			if(valid_data[k].sec>sec){
				cout << parked[k-1] << endl;
			}else if(valid_data[k].sec==sec){
				cout << parked[k] << endl;
			}
		}

		cout <<  << endl;
		last_index = j;
	}

	vector<Stat> stat;
	for(auto iter = parked.begin(); iter!=parked.end(); ++iter){
		Stat s;
		s.duration = (iter->second.end()-1)->duration;
		s.plate = iter->first;
		stat.push_back(s);
	}

	sort(stat.begin(), stat.end(), cmp);

	cout << stat.begin()->plate;
	for(auto iter=++stat.begin(); 
		iter!=stat.end() && iter->duration == stat.begin()->duration;
		++iter){
			cout << ' ' << iter->plate;
	}

	cout << ' ' << sec2hms(stat.begin()->duration);

	return 0;
}