#include <iostream>
#include <string>

using namespace std;

int main()
{
	string answer;
	int N;
	cin >> answer >> N;
	string buf;
	getline(cin, buf);

	int i;
	for (i = 1; i <= N; i++) {
		string s;
		getline(cin, s);
		if (s == "#") break;
		if (s == answer) {
			cout << "Welcome in" << endl;
			break;
		}
		else
			cout << "Wrong password: " << s << endl;
	}

	if (i > N) cout << "Account locked" << endl;
	return 0;
}