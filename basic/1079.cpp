#include <string>
#include <iostream>
#include <stack>

using namespace std;

int c2i(char c)
{
	return c - '0';
}

bool is_palind(string s)
{
	for(int i=0; i<s.length(); i++){
		if(s[i]!=s[s.length()-1-i])
			return false;
	}

	return true;
}

string reverse_string(string &s)
{
	string r;
	for(int i=0; i<s.length(); i++){
		r += s[s.length()-1-i];
	}

	return r;
}

string add_string(string &x, string &y)
{
	string str;
	stack<char> s;
	int carry = 0;
	int i = x.length()-1, j = y.length()-1;
	while(i>=0 || j>=0 || carry){
		int num_x = i>=0 ? c2i(x[i]) : 0;
		int num_y = j>=0 ? c2i(y[j]) : 0;
		s.push((num_x + num_y + carry)%10+'0');
		carry = (num_x + num_y + carry)/10;
		i--;
		j--;
	}

	while(s.top()=='0')
		s.pop();

	while(!s.empty()){
		str += s.top();
		s.pop();
	}
	return str;
}

int main()
{
	string s;
	cin >> s;

	int count = 0;
	while(!is_palind(s)){
		string r = reverse_string(s);
		cout << s << " + " << r << " = ";
		s = add_string(s, r);
		cout << s << endl;
		count++;
		if(count==10){
			cout << "Not found in 10 iterations." << endl;
			return 0;
		}
	}

	cout << s << " is a palindromic number." << endl;

	return 0;
}