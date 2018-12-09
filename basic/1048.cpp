#include <iostream>
#include <string>

using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	string digits = "0123456789JQK";
	for(int i=0; i<(int)B.length()- (int)A.length(); i++){
		cout << B[i];
	}

	for(int i=0; i<A.length(); i++) {
		int order = A.length() - i;
		int index = i + (int)B.length()-(int)A.length();
		if(index<0) continue;
		if(order%2){
			cout << digits[(A[i]-'0' + B[index]-'0')%13];
		} else {
			 int value = (B[index]-'0') - (A[i]- '0');
			 if(value < 0)
				 value += 10;
			 cout << value;
		}
	}

	cout << endl;
	return 0;
}