#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;
struct Record{
	string plate;
	int sec;
	int state;
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
	freopen("..\\..\\PTA\\1095.txt", "r", stdin);
#endif

	int N, K;
	cin >> N >> K;

	vector<Record> data(N);
	for(int i=0; i<N; i++){
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
		if(data[i].plate == data[i+1].plate && data[i].state==1 && data[i+1].state==-1){
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
		
		int j = last_index;
		for (; j < valid_data.size() - 1; j++) {
			if (valid_data[j+1].sec > sec) {
				cout << parked[j] << endl;
				break;
			}
		}

		if (j == valid_data.size() - 1) {
			cout << parked[j] << endl;
		}

		last_index = j;
	}

	set<string> stat;
	for (int i = 0; i < valid_data.size(); i++) {
		if (map_duration[valid_data[i].plate] == max_duration) {
			stat.insert(valid_data[i].plate);
		}
	}

	for (auto iter = stat.begin(); iter != stat.end(); ++iter) {
		cout << *iter << ' ';
	}

	cout << sec2hms(max_duration);

	return 0;
}