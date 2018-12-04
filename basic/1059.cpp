#include <string>
#include <iostream>
#include <vector>

using namespace std;
#define MAX_N 10005
int PRIMES[MAX_N+1];

void init_prime()
{
	for(int i=2; i*i<=MAX_N; i++)
		for(int j=i; j*i<=MAX_N; j++)
			PRIMES[i*j] = 1;
}

struct Person{
	int order;
	int prime;
	bool checked;
};
vector<Person> data(MAX_N);

int main()
{
	string prime_string = "Minion";
	string other_string = "Chocolate";
	string winner_string = "Mystery Award";
	string checked_string = "Checked";
	string error_string = "Are you kidding?";

	init_prime();

	int N;
	cin >> N;

	for(int i=0; i<N; i++){
		int index;
		cin >> index;
		Person p;
		p.order = i+1;
		if(p.order==1)
			p.prime = -1;
		else if(PRIMES[p.order]==0)
			p.prime = 1;
		else
			p.prime = 0;
		p.checked = false;
		data[index] = p;
	}

	int K;
	cin >> K;

	while(K--){
		int index;
		cin >> index;
		printf("%04d: ", index);
		if(data[index].order==0)
			cout << error_string << endl;
		else if(data[index].checked)
			cout << checked_string << endl;
		else if(data[index].prime==-1){
			cout << winner_string << endl;
			data[index].checked = true;
		}else if(data[index].prime==1){
			cout << prime_string << endl;
			data[index].checked = true;
		}else if(data[index].prime==0){
			cout << other_string << endl;
			data[index].checked = true;
		}else{
			cout << "Error" << endl;
		}
	}

	return 0;
}