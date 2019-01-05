#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\PTA\\1090.txt" , "r", stdin);
#endif

	int N;
	double P, r;

	cin >> N >> P >> r;

	vector<int> level(N);
	vector<int> chain(N);

	for(int i=0; i<N; i++){
		scanf("%d", &chain[i]);
	}

	int max_level = 0;
	int max_count = 0;
	for(int i=0; i<N; i++){
		int temp = i;
		while(chain[temp]!=-1){
			level[i]++;
			if(level[chain[temp]]!=0){
				level[i] += level[chain[temp]];
				break;
			}

			temp = chain[temp];
		}

		if(level[i]>max_level){
			max_level = level[i];
			max_count = 1;
		} else if(level[i]==max_level){
			max_count++;
		}
	}

	printf("%.2f %d\n", P*pow((1.0+r*0.01), max_level), max_count);

	return 0;
}