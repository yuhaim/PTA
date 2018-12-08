#include <iostream>
#include <cctype>
#include <string>
#include <cstdio>

using namespace std;

enum {VALID, SHORT, INVALID, NONUM, NOALPHA};

int check(string &s)
{
	if(s.length() < 6)
		return SHORT;
	
	bool has_alpha = false;
	bool has_num = false;
	
	for(int i=0; i<s.length(); i++){
		if(isalpha(s[i]))
			has_alpha = true;
		else if(isdigit(s[i]))
			has_num = true;
		else if(s[i]!='.')
			return INVALID;
	}
	
	if(!has_alpha)
		return NOALPHA;
	if(!has_num)
		return NONUM;
	
	return VALID;
}

int main()
{
	string valid_str = "Your password is wan mei.";
	string short_str = "Your password is tai duan le.";
	string invalid_str = "Your password is tai luan le.";
	string nonum_str = "Your password needs shu zi.";
	string noalpha_str = "Your password needs zi mu.";
	int N;
	cin >> N;
	getchar();

	for(int i=0; i<N; i++){
		string s;
		getline(cin, s);
		
		int result = check(s);
		switch(result){
			case VALID:
				cout << valid_str << endl;
				break;
			case SHORT:
				cout << short_str << endl;
				break;
			case INVALID:
				cout << invalid_str << endl;
				break;
			case NONUM:
				cout << nonum_str << endl;
				break;
			case NOALPHA:
				cout << noalpha_str << endl;
				break;				
		}
	}
	
	return 0;
}
