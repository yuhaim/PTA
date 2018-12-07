#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> original_data(N);
	for(int i=0;i<N;i++){
		cin >> original_data[i];
	}

	vector<int> sorted_data(N);
	for(int i=0;i<N;i++){
		cin >> sorted_data[i];
	}

	bool is_insert = false;
	int j=1;
	int mark;
	while(j<N && sorted_data[j] >= sorted_data[j-1]){
		j++;
	}

	mark = j;

	while(j<N && sorted_data[j]==original_data[j]){
		j++;
	}

	if(j==N)
		is_insert = true;

	if(is_insert){
		cout << "Insertion Sort" << endl;
		if(mark==N){
			;
		}else{
			int i=mark-1;
			int curr = sorted_data[i+1];
			while(i>=0 && curr < sorted_data[i]){
				sorted_data[i+1] = sorted_data[i];
				i--;
			}
			sorted_data[i+1] = curr;
		}
	}
	else{
		cout << "Merge Sort" << endl;
	}

	for(int i=0; i<N-1; i++){
		cout << sorted_data[i] << ' ';
	}
	cout << sorted_data[N-1] << endl;

	return 0;
}