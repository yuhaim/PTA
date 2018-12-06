#include <iostream>
#include <string>
#include <stack>

using namespace std;

int c2i(char c) 
{
	return c - '0';
}

int main()
{
	string table;
	string x, y;

	cin >> table >> x >> y;
	int i = x.length() - 1;
	int j = y.length() - 1;
	int k = table.length() - 1;
	int carry = 0;
	stack<int> s;

	while (i >= 0 || j >= 0 || carry) {
		int inc = (k < 0 || c2i(table[k]) == 0) ? 10 : c2i(table[k]);
		int num_x = i < 0 ? 0 : c2i(x[i]);
		int num_y = j < 0 ? 0 : c2i(y[j]);

		int sum = num_x + num_y + carry;

		s.push(sum%inc);
		carry = sum / inc;
		i--;
		j--;
		k--;
	}

	while (!s.empty() && s.top()==0) {
		s.pop();
	}

	if (s.empty()) {
		cout << 0;
	}
	else {
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
	}

	cout << endl;
	return 0;
}