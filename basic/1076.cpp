#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;

	while(N--){
		for(int i=0;i<4;i++){
			string s;
			cin >> s;
			if(s[2]=='T')
				cout << s[0] - 'A' + 1;
		}
	}

	return 0;
}