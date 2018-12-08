#include <iostream>
#include <string>

using namespace std;

int main()
{
	int d, N;
	cin >> d >> N;

	string s, temp;
	s += d + '0';
	
	for(int i=0; i<N-1; i++){
		temp = "";
		for(int j=0; j<s.length(); j++){
			int count = 0;
			while(j+1<s.length() && s[j]==s[j+1]){
				j++;
				count++;
			}
			count++;
			
			temp += s[j];
			temp += count + '0';
		}
		s = temp;
	}

	cout << s <<endl;
	return 0;
}