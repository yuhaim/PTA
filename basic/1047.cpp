#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;

	map<int, int> data;
	while(N--){
		int team, id, score;
		scanf("%d-%d %d", &team, &id, &score);
		data[team] += score;
	}

	int max_team, max_score = 0;
	for(auto x=data.begin(); x!=data.end(); x++){
		if(x->second > max_score){
			max_score = x->second;
			max_team = x->first;
		}
	}

	cout << max_team << ' ' << max_score << endl;

	return 0;
}