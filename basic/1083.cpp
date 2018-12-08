#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	map<int, int, greater<int> > repeats;
	for(int i=1; i<=N; i++){
		int x;
		cin >> x;
		repeats[abs(x-i)]++;
	}

	for(map<int, int, greater<int> >::iterator iter = repeats.begin();
		iter!=repeats.end(); iter++){
		if(iter->second>1)
			cout << iter->first << ' ' << iter->second << endl;
	}

	return 0;
}
