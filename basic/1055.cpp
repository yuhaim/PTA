#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef struct Person{
	string Name;
	int Height;
};

bool compare(Person &x, Person &y)
{
	if(x.Height != y.Height)
		return x.Height < y.Height;
	else
		return x.Name > y.Name;
}

int main()
{
	int N, K;
	cin >> N >> K;
	
	vector<Person> data;
	for(int i=0; i<N; i++){
		Person p;
		cin >> p.Name >> p.Height;
		data.push_back(p);
	}

	sort(data.begin(), data.end(), compare);
	int index = N-1;

	int len = N - N/K*(K-1);
	int mid = len/2+1-1;
	int s = 1;
	vector<Person> last_line(len);
	for(int j=0; j<len; j++){
		if(j==0)
			last_line[mid] = data[index--];
		else if(j%2)
			last_line[mid + (j/2+1)*s] = data[index--];
		else
			last_line[mid + j/2*s] = data[index--];
		s = -s;
	}

	for(int k=0; k<len-1; k++){
		cout << last_line[k].Name << ' ';
	}
	cout << last_line[len-1].Name << endl;

	for(int i=0; i<K-1; i++){
		int len = N/K;
		int mid = len/2+1-1;
		int s = 1;
		vector<Person> line(len);
		for(int j=0; j<len; j++){
			if(j==0)
				line[mid] = data[index--];
			else if(j%2)
				line[mid + (j/2+1)*s] = data[index--];
			else
				line[mid + j/2*s] = data[index--];
			s = -s;
		}

		for(int k=0; k<len-1; k++){
			cout << line[k].Name << ' ';
		}
		cout << line[len-1].Name << endl;
	}

	return 0;
}