#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int trans(char c)
{
	if(islower(c))
		return c-'a'+1;
	else if(isupper(c))
		return c-'A'+1;
	else
		return 0;
}

int main()
{
	string s;
	getline(cin, s);
	int N = 0;
	for(int i=0; i<s.length(); i++){
		N += trans(s[i]);
	}

	int zeros = 0, ones = 0;
	while(N){
		if(N%2) ones++;
		else zeros++;
		N = N >> 1;
	}

	cout << zeros << ' ' << ones << endl;

	return 0;
}