#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	for(int i=0; i<N; i++){
		int score;
		cin >> score;
		vector<int> valid;
		double temp;
		for(int j=1; j<N; j++){
			cin >> temp;
			if(temp>=0 && temp<=M)
				valid.push_back(temp);
		}

		sort(valid.begin(), valid.end());
		temp = 0;
		for(int k=1; k<valid.size()-1; k++)
			temp += valid[k];
		temp = temp/(valid.size()-2);
		cout << (int)((score + temp)*0.5+0.5) << endl;
	}

	return 0;
}