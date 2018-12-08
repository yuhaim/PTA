#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
vector<int> book[100005];
int items[1005];
int main()
{
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		book[x].push_back(y);
		book[y].push_back(x);
	}

	for(int j=0; j<M; j++){
		int count;
		scanf("%d", &count);
		
		for(int k=0; k<count; k++){
			scanf("%d", &items[k]);
		}
	
		int m;
		for(m=0; m<count-1; m++){
			for(int n=m+1; n<count; n++){
				if(book[items[m]].size()!=0){
					for(vector<int>::iterator iter = book[items[m]].begin();
						iter!=book[items[m]].end(); iter++){
						if(*iter==items[n]){
							printf("No\n");
							m = count;
							break;
						}
					}
				}
			}
		}
		if(m==count-1)
			printf("Yes\n");
	}

	return 0;
}