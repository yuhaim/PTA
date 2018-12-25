#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	string A;
	string B;

	getline(cin, A);
	getline(cin, B);

	set<char> record;

	for(int i=0; i<A.length(); i++){
		if(record.find(A[i])!=record.end()){
		
		} else {
			record.insert(A[i]);
			cout << A[i];
		}
	}

	for(int i=0; i<B.length(); i++){
		if(record.find(B[i])!=record.end()){
		
		} else {
			record.insert(B[i]);
			cout << B[i];
		}
	}

	return 0;
}
