#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>

using namespace std;

void compress(string &s)
{
	int i = 0;
	while(i<s.length()){
		char c = s[i];
		int count = 0;
		while(i+1<s.length() && s[i+1]==c){
			i++;
			count++;
		}

		if(count > 0)
			cout << count + 1;
		cout << c;
		i++;
	}
	cout << endl;
}

void decompress(string &s)
{
	int i = 0;
	while(i<s.length()){
		char c = s[i];
		if(isdigit(c)){
			int rep = c - '0';
			while(isdigit(s[i+1])){
				rep = 10*rep + s[i+1] - '0';
				i++;
			}

			for(int j=0; j<rep;j++)
				cout << s[i+1];
			i+=2;
		}else{
			cout << c;
			i++;
		}
	}
	cout << endl;
}

int main()
{
	char cmd;
	cin >> cmd;

	getchar();
	string s;
	getline(cin, s);

	switch(cmd){
	case 'C':
		compress(s);
		break;
	case 'D':
		decompress(s);
		break;
	}

	return 0;
}