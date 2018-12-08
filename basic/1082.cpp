#include <iostream>
#include <string>

using namespace std;

int sqrt_dist(int x, int y)
{
	return x*x + y*y;
}

int main()
{
	int N;
	cin >> N;

	int min_value = 100000;
	int max_value = -1;
	string max_id;
	string min_id;

	while(N--){
		string id;
		int x, y;
		cin >> id;
		cin >> x >> y;
		int temp = sqrt_dist(x, y);
		if(max_value<temp){
			max_value = temp;
			max_id = id;
		}
		if(min_value>temp){
			min_value = temp;
			min_id = id;
		}
	}

	cout << min_id << ' ' << max_id << endl;

	return 0;
}