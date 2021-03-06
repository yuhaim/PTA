#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int M, N, S;
	cin >> M >> N >> S;

	int count = 0;
	bool skip = false;
	set<string> record;
	for (int i = 1; i <= M; i++) {
		string s;
		cin >> s;
		auto result = record.find(s);
		if (result != record.end()) {
			S++;
			continue;
		}else if (i==S) {
			cout << s << endl;
			record.insert(s);
			count++;
			S += N;
		}
	}
	
	if (count == 0)
		cout << "Keep going..." << endl;
	return 0;
}