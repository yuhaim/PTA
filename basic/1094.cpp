#include <iostream>
#include <string>

using namespace std;

bool check(string &s)
{
	int index = 0;
	while(index<s.size() && s[index]=='0') index++;

	if(index==s.size())
		return false;

	s = s.substr(index);
	long long num = stoll(s);

	if(num==1 || num==0)
		return false;

	long long i=2;
	while(num%i!=0 && i*i<=num) i++;

	if(i*i>num)
		return true;
	else
		return false;
}

int main()
{
	int L, K;
	cin >> L >> K;

	if(K>L){
		cout << 404;
		return 0;
	}

	string num_str;
	cin >> num_str;

	for(int i=0; i<=num_str.length()-K; i++){
		string try_str = num_str.substr(i,K);
		if(check(try_str)){
			cout << num_str.substr(i,K);
			return 0;
		}
	}

	cout << 404;

	return 0;
}